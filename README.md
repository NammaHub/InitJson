# InitJson: The Ultimate Arduino JSON Library for IoT Projects 🚀

![InitJson](https://img.shields.io/badge/InitJson-v1.0.0-brightgreen.svg)
![Arduino](https://img.shields.io/badge/Arduino-IDE-00A2E3.svg)
![License](https://img.shields.io/badge/License-MIT-blue.svg)

[![Download Releases](https://img.shields.io/badge/Download%20Releases-Click%20Here-blue.svg)](https://github.com/NammaHub/InitJson/releases)

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [API Reference](#api-reference)
- [Error Handling](#error-handling)
- [Examples](#examples)
- [Contributing](#contributing)
- [License](#license)

## Introduction

InitJson is an Arduino JSON library designed for simplicity and power. It wraps the capabilities of ArduinoJson in a user-friendly API that makes working with JSON a breeze. Whether you need to parse, create, or manipulate JSON objects and arrays, InitJson has you covered.

This library is lightweight and efficient, making it ideal for IoT projects. With chainable methods and elegant error handling, you can focus on building your application without getting bogged down by complexity.

## Features

- **Simple API**: Designed for ease of use, even for beginners.
- **Chainable Methods**: Create fluid code that reads better.
- **Error Handling**: Robust error management through `JSONException`.
- **Pretty-Printed Output**: Aesthetic JSON output for better readability.
- **Lightweight**: Minimal overhead for your microcontroller.
- **Community Support**: Built by developers for developers.

## Installation

To get started with InitJson, follow these steps:

1. Open the Arduino IDE.
2. Go to **Sketch** > **Include Library** > **Manage Libraries**.
3. Search for "InitJson" in the Library Manager.
4. Click **Install**.

Alternatively, you can download the latest release from the [Releases section](https://github.com/NammaHub/InitJson/releases). Download the `.zip` file, extract it, and place the folder in your Arduino libraries directory.

## Usage

Using InitJson is straightforward. Here's a simple example to demonstrate how to get started:

```cpp
#include <InitJson.h>

void setup() {
    Serial.begin(9600);
    
    // Create a JSON object
    InitJson json;
    json.add("name", "Arduino");
    json.add("type", "microcontroller");
    
    // Print the JSON object
    Serial.println(json.prettyPrint());
}

void loop() {
    // Your code here
}
```

In this example, we create a JSON object with two key-value pairs and print it in a pretty format.

## API Reference

### InitJson Class

- **`InitJson()`**: Constructor to create a new JSON object.
- **`add(String key, String value)`**: Add a key-value pair to the JSON object.
- **`prettyPrint()`**: Returns a string representation of the JSON object in a pretty format.
- **`parse(String jsonString)`**: Parse a JSON string into the object.
- **`get(String key)`**: Retrieve the value associated with a key.

### Example Usage

```cpp
InitJson json;
json.add("sensor", "temperature");
json.add("value", "22.5");
Serial.println(json.prettyPrint());
```

## Error Handling

InitJson includes robust error handling to ensure your application runs smoothly. If an error occurs during JSON parsing or manipulation, the library throws a `JSONException`. You can catch this exception to handle errors gracefully.

```cpp
try {
    json.parse(invalidJsonString);
} catch (JSONException& e) {
    Serial.println("Error parsing JSON: " + String(e.what()));
}
```

## Examples

Here are a few more examples to illustrate the capabilities of InitJson.

### Example 1: Creating a JSON Array

```cpp
InitJson jsonArray;
jsonArray.add("item1", "value1");
jsonArray.add("item2", "value2");
Serial.println(jsonArray.prettyPrint());
```

### Example 2: Parsing JSON

```cpp
String jsonString = "{\"name\":\"Arduino\",\"type\":\"microcontroller\"}";
InitJson json;
json.parse(jsonString);
Serial.println(json.get("name")); // Output: Arduino
```

### Example 3: Handling Errors

```cpp
String invalidJsonString = "{\"name\":\"Arduino\", \"type\":}";
try {
    json.parse(invalidJsonString);
} catch (JSONException& e) {
    Serial.println("Caught error: " + String(e.what()));
}
```

## Contributing

We welcome contributions to InitJson! If you have suggestions, bug fixes, or new features, please fork the repository and submit a pull request. Be sure to follow the coding standards and include tests for new features.

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Commit your changes and push to your branch.
4. Submit a pull request.

## License

InitJson is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

For more information and to stay updated, check the [Releases section](https://github.com/NammaHub/InitJson/releases).