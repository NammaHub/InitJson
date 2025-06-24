#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include <Arduino.h>
#include <ArduinoJson.h>
#include "JSONException.h"

namespace InitJson {
    class JSONArray; // Forward declaration
}

// Custom converter for JSONArray
namespace ArduinoJson {
namespace V742JB11 {
inline void convertToJson(const InitJson::JSONArray& obj, JsonVariant dst);
}
}

namespace InitJson {

class JSONObject {
private:
    DynamicJsonDocument doc;
    String lastError;

public:
    JSONObject(size_t capacity = 1024);
    JSONObject(const String& jsonString, size_t capacity = 1024);

    template<typename T>
    JSONObject& put(const String& key, T value) {
        doc[key] = value;
        return *this;
    }

    JSONObject& put(const String& key, const JSONObject& value);
    JSONObject& put(const String& key, const JSONArray& value);

    JsonVariantConst get(const String& key) const;
    String optString(const String& key, const String& defaultValue = "") const;
    int optInt(const String& key, int defaultValue = 0) const;
    double optDouble(const String& key, double defaultValue = 0.0) const;
    bool optBoolean(const String& key, bool defaultValue = false) const;
    bool has(const String& key) const;
    void remove(const String& key);
    size_t length() const;
    String toString() const;
    String toStringPretty() const;
    JsonObject raw() const;
    String getLastError() const;

    class Iterator {
    private:
        JsonObjectConst obj;
        JsonObjectConstIterator current;
        JsonObjectConstIterator end;

    public:
        Iterator(JsonObjectConst obj) : obj(obj), current(obj.begin()), end(obj.end()) {}

        bool hasNext() const {
            return current != end;
        }

        void next() {
            ++current;
        }

        String key() const {
            if (hasNext()) {
                return String((*current).key().c_str());
            }
            return String();
        }

        JsonVariantConst value() const {
            if (hasNext()) {
                return (*current).value();
            }
            return JsonVariantConst();
        }
    };

    Iterator keys() const;
};

} // namespace InitJson

#endif