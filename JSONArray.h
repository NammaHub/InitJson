#ifndef JSON_ARRAY_H
#define JSON_ARRAY_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "JSONException.h"
#include "JSONObject.h"

namespace InitJson {
    class JSONArray;
}

// Custom converter for JSONArray
namespace ArduinoJson {
namespace V742JB11 {
inline void convertToJson(const InitJson::JSONArray& src, JsonVariant dst);
}
}

namespace InitJson {

class JSONArray {
private:
    DynamicJsonDocument doc;
    JsonArray array;
    String lastError;

public:
    JSONArray(size_t capacity = 1024) : doc(capacity), array(doc.to<JsonArray>()) {}

    JSONArray(const String& jsonString, size_t capacity = 1024) : doc(capacity), lastError("") {
        DeserializationError error = deserializeJson(doc, jsonString);
        if (error) {
            Serial.println("Invalid JSON array string");
            lastError = "Invalid JSON array string";
            doc.clear();
            doc.to<JsonArray>();
            array = doc.as<JsonArray>();
            return;
        }
        if (!doc.is<JsonArray>()) {
            Serial.println("JSON string is not an array");
            lastError = "JSON string is not an array";
            doc.clear();
            doc.to<JsonArray>();
        }
        array = doc.as<JsonArray>();
    }

    template<typename T>
    JSONArray& put(T value) {
        array.add(value);
        return *this;
    }

    JSONArray& put(const JSONObject& obj) {
        array.add(obj.raw());
        return *this;
    }

    JSONArray& put(const JSONArray& arr) {
        array.add(arr.raw());
        return *this;
    }

    JsonVariantConst get(int index) const {
        if (index < 0 || index >= array.size()) {
            Serial.println("Index out of bounds: " + String(index));
            return JsonVariantConst();
        }
        return array[index];
    }

    String optString(int index, const String& defaultValue = "") const {
        if (index < 0 || index >= array.size()) return defaultValue;
        JsonVariantConst var = array[index];
        return var.is<const char*>() ? String(var.as<const char*>()) : defaultValue;
    }

    int optInt(int index, int defaultValue = 0) const {
        if (index < 0 || index >= array.size()) return defaultValue;
        JsonVariantConst var = array[index];
        return var.is<int>() ? var.as<int>() : defaultValue;
    }

    double optDouble(int index, double defaultValue = 0.0) const {
        if (index < 0 || index >= array.size()) return defaultValue;
        JsonVariantConst var = array[index];
        return var.is<double>() ? var.as<double>() : defaultValue;
    }

    bool optBoolean(int index, bool defaultValue = false) const {
        if (index < 0 || index >= array.size()) return defaultValue;
        JsonVariantConst var = array[index];
        return var.is<bool>() ? var.as<bool>() : defaultValue;
    }

    void remove(int index) {
        array.remove(index);
    }

    size_t length() const {
        return array.size();
    }

    String toString() const {
        String output;
        serializeJson(array, output);
        return output;
    }

    String toStringPretty() const {
        String output;
        serializeJsonPretty(array, output);
        return output;
    }

    JsonArray raw() const {
        return array;
    }

    String getLastError() const {
        return lastError;
    }

    friend void ArduinoJson::V742JB11::convertToJson(const JSONArray& src, JsonVariant dst);
};

} // namespace InitJson

#endif