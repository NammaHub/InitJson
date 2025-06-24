#include <InitJson.h>
using namespace InitJson;
void setup() {
  Serial.begin(9600);

  // Create a JSON object, no cap
  JSONObject json;
  json.put("name", "Rayhan")
      .put("age", 42)
      .put("isCool", true);

  // Nested JSON? Bet
  JSONArray vibes;
  vibes.put("chill").put("lit").put("fire");
  json.put("vibes", vibes);

  // Print that pretty JSON
  Serial.println(json.toStringPretty());

  // Iterate keys like a TikTok dance
  JSONObject::Iterator keys = json.keys();
  while (keys.hasNext()) {
    Serial.print("Key: ");
    Serial.println(keys.key());
    keys.next();
  }
}

void loop() {
  // We out here chilling
}
