# altEscKeyAndMouseMove
Sending Alt + Esc keycodes (task switch key comibation for windows) and random mouse moving signal periodically with Digispark.
This sketch is only for a small "Proof of Concept" and you would see the window focus is changing one to other and the mouse cursor is dancing randomly if you would connect your Digispark running this sketch to a windows PC.

DigiMouse and DigiKeyboard designed for Digispark cannot be complied when they are used at the same time (in a same sketch),
while mouse and keyboard support provided in TrinketHidCombo causes no such problems.
(this article was very much helpful http://digistump.com/board/index.php?topic=2581.0 Many thanks to the commenters.)

Be sure to use subroutines defined in TrinketHidCombo.h. You cannot compile if you try to use the ones defined in TrinketMouse.h and TrinketKeyboard in same sketches.
