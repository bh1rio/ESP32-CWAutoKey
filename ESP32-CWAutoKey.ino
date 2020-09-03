#include <BleMouse.h>

const int mouseLeftButton = 3;
const int mouseRightButton = 4;

int responseDelay = 10; // response delay of the mouse, in ms

BleMouse bleMouse;

void setup()
{
    Serial.begin(115200);
    Serial.println("Starting BLE work!");

    pinMode(mouseLeftButton, INPUT_PULLUP);
    pinMode(mouseRightButton, INPUT_PULLUP);

    bleMouse.begin();
}

void loop()
{
    if (bleMouse.isConnected())
    {
        // read the buttons:
        int clickLeftState = digitalRead(mouseLeftButton);
        int clickRightState = digitalRead(mouseRightButton);

        // if the mouse button is pressed:
        if (clickLeftState == LOW)
        {
            // if the mouse is not pressed, press it:
            if (!bleMouse.isPressed(MOUSE_LEFT))
            {
                Serial.println("Mouse Left Key is pressed!");
                bleMouse.press(MOUSE_LEFT);
            }
        }
        // else the mouse button is not pressed:
        else
        {
            // if the mouse is pressed, release it:
            if (bleMouse.isPressed(MOUSE_LEFT))
            {
                Serial.println("Mouse Left Key is released!");
                bleMouse.release(MOUSE_LEFT);
            }
        }

        if (clickRightState == LOW)
        {
            if (!bleMouse.isPressed(MOUSE_RIGHT))
            {
                Serial.println("Mouse Right Key is pressed!");
                bleMouse.press(MOUSE_RIGHT);
            }
        }
        else
        {
            if (bleMouse.isPressed(MOUSE_RIGHT))
            {
                Serial.println("Mouse Right Key is released!");
                bleMouse.release(MOUSE_RIGHT);
            }
        }

        // a delay so the mouse doesn't move too fast:
        delay(responseDelay);
    }
}