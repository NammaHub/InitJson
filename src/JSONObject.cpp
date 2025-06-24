#include "JSONObject.h"
#include "JSONArray.h"

namespace ArduinoJson {
namespace V742JB11 {
void convertToJson(const InitJson::JSONArray& src, JsonVariant dst) {
    dst.set(src.raw()); // Convert JSONArray to JsonArray
}
}
}

namespace InitJson {

JSONObject::JSONObject(size_t capacity) : doc(capacity), lastError("") {
    doc.clear();
    doc.to<JsonObject>();
}

JSONObject::JSONObject(const String& jsonString, size_t capacity) : doc(capacity), lastError("") {
    DeserializationError error = deserializeJson(doc, jsonString);
    if (error) {
        Serial.println("Invalid JSON string: " + String(error.c_str()));
        lastError = "Invalid JSON string: " + String(error.c_str());
        doc.clear();
        doc.to<JsonObject>();
        return;
    }
    if (!doc.is<JsonObject>()) {
        Serial.println("JSON string is not an object");
        lastError = "JSON string is not an object";
        doc.clear();
        doc.to<JsonObject>();
    }
}

JSONObject& JSONObject::put(const String& key, const JSONObject& value) {
    doc[key] = value.raw();
    return *this;
}

JSONObject& JSONObject::put(const String& key, const JSONArray& value) {
    doc[key] = value; // Uses convertToJson
    return *this;
}

JsonVariantConst JSONObject::get(const String& key) const {
    if (!doc.containsKey(key)) {
        return JsonVariantConst();
    }
    return doc[key];
}

String JSONObject::optString(const String& key, const String& defaultValue) const {
    if (!doc.containsKey(key)) return defaultValue;
    JsonVariantConst val = doc[key];
    return val.is<const char*>() ? String(val.as<const char*>()) : defaultValue;
}

int JSONObject::optInt(const String& key, int defaultValue) const {
    if (!doc.containsKey(key)) return defaultValue;
    JsonVariantConst val = doc[key];
    return val.is<int>() ? val.as<int>() : defaultValue;
}

double JSONObject::optDouble(const String& key, double defaultValue) const {
    if (!doc.containsKey(key)) return defaultValue;
    JsonVariantConst val = doc[key];
    return val.is<double>() ? val.as<double>() : defaultValue;
}

bool JSONObject::optBoolean(const String& key, bool defaultValue) const {
    if (!doc.containsKey(key)) return defaultValue;
    JsonVariantConst val = doc[key];
    return val.is<bool>() ? val.as<bool>() : defaultValue;
}

bool JSONObject::has(const String& key) const {
    return doc.containsKey(key);
}

void JSONObject::remove(const String& key) {
    doc.remove(key);
}

size_t JSONObject::length() const {
    return doc.size();
}

String JSONObject::toString() const {
    String output;
    serializeJson(doc, output);
    return output;
}

String JSONObject::toStringPretty() const {
    String output;
    serializeJsonPretty(doc, output);
    return output;
}

JsonObject JSONObject::raw() const {
    return doc.to<JsonObject>();
}

String JSONObject::getLastError() const {
    return lastError;
}

JSONObject::Iterator JSONObject::keys() const {
    return Iterator(doc.as<JsonObjectConst>());
}

} // namespace InitJson