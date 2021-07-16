#include <TrinketHidCombo.h>

#define LED_PIN 1

#define MOUSE_INTERVAL      100 // ms (approx.)
#define KEYBOARD_INTERVAL   1000
#define ALT_PRESS_DELAY     200
#define ESC_PRESS_DURATION  100
#define MOUSE_MOVE_MAX      100

int mouse_counter = 0, keyboard_counter = 0;
int alt_press_counter = 0, esc_press_counter = 0;
boolean alt_on = false, esc_on = false;

void setup() {
  // put your setup code here, to run once:

  randomSeed(analogRead(0));
  pinMode(LED_PIN, OUTPUT);
  TrinketHidCombo.begin();

}

void loop() {
  TrinketHidCombo.mouseMove(0, 0, 0);
  TrinketHidCombo.poll();

  mouse_counter++;
  if (mouse_counter > MOUSE_INTERVAL) {
    TrinketHidCombo.mouseMove(random(MOUSE_MOVE_MAX) * 2 - MOUSE_MOVE_MAX, random(MOUSE_MOVE_MAX) * 2 - MOUSE_MOVE_MAX, 0);
    mouse_counter = 0;
  }

  keyboard_counter++;

  if (keyboard_counter > KEYBOARD_INTERVAL) {
    if (!alt_on) {
      alt_on = true;
      digitalWrite(LED_PIN, HIGH);
      TrinketHidCombo.pressKey(KEYCODE_MOD_LEFT_ALT, 0);
      alt_press_counter = 0;

    } else { // alt is on
      alt_press_counter++;
      if (alt_press_counter > ALT_PRESS_DELAY) {
        if (!esc_on) {
          esc_on = true;
          TrinketHidCombo.pressKey(KEYCODE_MOD_LEFT_ALT, KEYCODE_ESC);
          esc_press_counter = 0;
        } else { // esc is on
          esc_press_counter++;
          if (esc_press_counter > ESC_PRESS_DURATION) {
            esc_on = false;
            alt_on = false;
            digitalWrite(LED_PIN, LOW);
            TrinketHidCombo.pressKey(0, 0);  // both alt and esc are released
            keyboard_counter = 0;
          }
        }
      }
    }
  }
  delay(1);
}
