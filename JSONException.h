#ifndef JSON_EXCEPTION_H
#define JSON_EXCEPTION_H

#include <Arduino.h>

namespace InitJson {

class JSONException {
private:
    String message;

public:
    JSONException(const String& msg) : message(msg) {}

    String what() const {
        return message;
    }
};

} // namespace InitJson

#endif