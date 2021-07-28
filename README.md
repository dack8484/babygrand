# babygrand
Baby Grand keyboard, designed by me.
It's a 31-key, alpha-staggered, choc only caseless board. V1 has been tested, V2 is on its way to me. I'll write firmware for V2 when it gets here, sue me.
![photo_2021-07-22_08-27-34](https://user-images.githubusercontent.com/55664712/127390575-40a80c1e-cb9b-4062-9069-d2af6b2e2beb.jpg)
my pic
![photo_2021-07-28_13-22-46](https://user-images.githubusercontent.com/55664712/127390581-4185c5bf-42b4-4379-8ea1-0de87ba8f0fa.jpg)
my pic again, now with the PCBs

To build it, solder some diodes with the black line facing the square pad, then solder some choc switches, then solder a pro micro with the TX pin matching the square pad. Extract the firmware and plop it over into qmk_firmware/keyboards, compile and test the keyboard, then make your own keymap and off you go!
