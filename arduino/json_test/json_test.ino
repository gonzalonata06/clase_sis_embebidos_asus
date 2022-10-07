// ArduinoJson - https://arduinojson.org
// Copyright © 2014-2022, Benoit BLANCHON
// MIT License
//
// This example shows how to deserialize a JSON document with ArduinoJson.
//
// https://arduinojson.org/v6/example/parser/

#include <ArduinoJson.h>
#include "FS.h"
#include "SPIFFS.h"
#include "Stream.h"

  String json_s; int n; char json_c[30]; StaticJsonDocument<16> doc; char nombre1[20];

#define FORMAT_SPIFFS_IF_FAILED true




void setup() {
  // Initialize serial port
Serial.begin(115200);
    delay(10);

    if(!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)){
        Serial.println("SPIFFS Mount Failed");
        return;
    }

  // Allocate the JSON document
  //
  // Inside the brackets, 200 is the capacity of the memory pool in bytes.
  // Don't forget to change this value to match your JSON document.
  // Use https://arduinojson.org/v6/assistant to compute the capacity.


  // StaticJsonDocument<N> allocates memory on the stack, it can be
  // replaced by DynamicJsonDocument which allocates in the heap.
  //
  // DynamicJsonDocument doc(200);

  // JSON input string.
  //
  // Using a char[], as shown here, enables the "zero-copy" mode. This mode uses
  // the minimal amount of memory because the JsonDocument stores pointers to
  // the input buffer.
  // If you use another type of input, ArduinoJson must copy the strings from
  // the input to the JsonDocument, so you need to increase the capacity of the
  // JsonDocument.


  
  
    File file_json = SPIFFS.open("/json_test.txt", "r");
    if(!file_json || file_json.isDirectory()){
        Serial.println("- failed to open file for reading");
       
    }
    else{


    while(file_json.available()){
      json_s = file_json.readString() ;
      
    }

    file_json.close();
    }

    n = json_s.length();
 
    // declaring character array
 
 
    // copying the contents of the
    // string to char array
    strcpy(json_c, json_s.c_str());


  
  //char json[] =
  //  "{\"sensor\":\"gps\",\"time\":1351824120,\"data\":[48.756080,2.302038]}";

  // Deserialize the JSON document
  DeserializationError error = deserializeJson(doc, json_c);

  // Test if parsing succeeds.
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }
  // Fetch values.
  //
  // Most of the time, you can rely on the implicit casts.
  // In other case, you can do doc["time"].as<long>();
  //const char* sensor = doc["sensor"];
  const char* nombre = doc["nombre_alumno"];
  strcpy(nombre1,nombre);

}

void loop(){

  Serial.println(nombre1);
  delay(5000);
  }

// See also
// --------
//
// https://arduinojson.org/ contains the documentation for all the functions
// used above. It also includes an FAQ that will help you solve any
// deserialization problem.
//
// The book "Mastering ArduinoJson" contains a tutorial on deserialization.
// It begins with a simple example, like the one above, and then adds more
// features like deserializing directly from a file or an HTTP request.
// Learn more at https://arduinojson.org/book/
// Use the coupon code TWENTY for a 20% discount ❤❤❤❤❤
