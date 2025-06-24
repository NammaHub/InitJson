InitJson - The JSON Lib That's Straight Fire 🔥
Yo, what's good? Welcome to InitJson, the slickest JSON library for Arduino that's got all the vibes. We're here to yeet those clunky JSON struggles into the void and make your Arduino projects pop off with clean, easy JSON handling. Built on the shoulders of the GOAT, ArduinoJson, InitJson is like that extra shot of espresso in your code—smooth, powerful, and ready to flex.
What's the Tea? ☕
InitJson is a lightweight, no-cap JSON library for Arduino that lets you parse, create, and manipulate JSON objects and arrays like a boss. Whether you're cooking up some IoT bangers or just vibing with sensor data, this lib's got your back. It's giving simplicity and power in one tight package.
Why InitJson Slaps:

EZ to Use: Chain methods like you're dropping bars in a rap battle.
Built on ArduinoJson: We stan the OG, so we wrapped it in a Gen Z glow-up.
Error Handling That's Bussin': JSONException keeps your code from yeeting itself into chaos.
No Skips: Handles JSON objects, arrays, and all the nested goodness with zero fuss.
Lightweight AF: Won't bloat your Arduino sketch, so you can keep it 💯.

What's in the Bag? 🎒

JSONObject: Your main character for key-value JSON objects. Put, get, remove, and iterate like a pro.
JSONArray: For when you need to stack those values in a list. Add, remove, and loop through arrays with ease.
JSONException: Catches those "oh no" moments when your JSON ain't valid.
Chaining Vibes: Methods like put() return the object so you can keep the flow going.
Pretty Printing: toStringPretty() makes your JSON look like it’s ready for the 'Gram.

Shade on the Competition 😎
Other JSON libs? Snooze. They're either too chunky, too basic, or straight-up ghost you when errors hit. InitJson takes the W by keeping it simple, wrapping ArduinoJson’s power in a clean API, and throwing in some spicy error handling. No shade to ArduinoJson though—Benoît Blanchon’s lib is the 🐐, and we’re just remixing it for the culture.
How to Get This W 🚀

Clone or Download: Yoink this repo from GitHub.
Install: Drop it in your Arduino libraries/ folder or add it via the Library Manager (if we’re in there, check it!).
Include: Slap #include <InitJson.h> in your sketch.
Vibe Out: Start parsing and creating JSON like you’re coding for clout.

Code That Slaps 📝
Here’s a quick taste of how InitJson makes your life a whole mood:
#include <InitJson.h>

void setup() {
  Serial.begin(115200);

  // Create a JSON object, no cap
  InitJson::JSONObject json;
  json.put("name", "Grok")
      .put("age", 42)
      .put("isCool", true);

  // Nested JSON? Bet
  InitJson::JSONArray vibes;
  vibes.put("chill").put("lit").put("fire");
  json.put("vibes", vibes);

  // Print that pretty JSON
  Serial.println(json.toStringPretty());

  // Iterate keys like a TikTok dance
  InitJson::JSONObject::Iterator keys = json.keys();
  while (keys.hasNext()) {
    Serial.print("Key: ");
    Serial.println(keys.key());
    keys.next();
  }
}

void loop() {
  // We out here chilling
}

Output (pretty-printed JSON, ready for the spotlight):
{
  "name": "Grok",
  "age": 42,
  "isCool": true,
  "vibes": [
    "chill",
    "lit",
    "fire"
  ]
}

Methods That Pop Off 🧨
JSONObject

put(key, value): Slap a key-value pair in there (chainable, duh).
get(key): Yoink a value by key.
optString(key, default): Grab a string or fallback if it’s ghosted.
optInt(key, default): Snag an int or roll with the default.
optDouble(key, default): Cop a double or take the L with a default.
optBoolean(key, default): Check if it’s true or false, or just vibe with the default.
has(key): Check if a key exists, no cap.
remove(key): Yeet a key-value pair.
length(): Count how many key-value pairs you got.
toString(): Get that JSON string, compact mode.
toStringPretty(): JSON string, but make it ✨ aesthetic ✨.
keys(): Iterator to loop through keys like you’re scrolling X.

JSONArray

put(value): Add a value to the array (chainable, obvs).
get(index): Grab a value by index.
optString(index, default): Snag a string or fallback.
optInt(index, default): Yoink an int or take the default.
optDouble(index, default): Cop a double or roll with the default.
optBoolean(index, default): Check true/false or vibe with the default.
remove(index): Yeet an element.
length(): How long’s the array? Find out.
toString(): JSON array string, compact style.
toStringPretty(): JSON array string, but it’s giving looks.

JSONException

what(): Spill the tea on what went wrong.

Dependencies (The Squad) 🫂

ArduinoJson (v7.0.0+): The backbone of this lib. Big props to Benoît Blanchon for keeping it 💯.
Arduino Core: Gotta have that Arduino framework to make it all work.

Installation (No Cap) 🛠️

Download the repo or grab the zip from GitHub.
Toss it into your Arduino libraries/ folder.
If you’re feeling fancy, add it via the Arduino IDE’s Library Manager (search InitJson).
Include it with #include <InitJson.h> and start cooking.

Contributing (Join the Glow-Up) 🌟
Wanna make this lib even more lit? Slide into the GitHub issues or PRs with your ideas. We’re all about that open-source vibe. Just keep it chill and follow the code style.
License (The Legal Tea) 📜
This project is licensed under the MIT License—do what you want, just don’t be sus. Check the LICENSE file for the full deets.
Shoutouts 📣

ArduinoJson for being the 🐐.
The Arduino community for keeping the maker vibes alive.
You, for checking out InitJson and making your projects pop off.

Bugs or Questions? 🐛
Hit us up on GitHub Issues. We’ll slide into your DMs (or issue threads) with the fix or some wisdom.

InitJson: The JSON lib that’s serving looks and functionality. Let’s get this bread! 🍞
