# altEscKeyAndMouseMove
Sending Alt + Esc keycodes (task switch key comibation for windows) and random mouse moving signal periodically with digispark.

DigiMouse and DigiKeyboard designed for digispark cannot be complied when they are used at the same time, 
while mouse and keyboard support provided in TrinketHidCombo causes no such problems.
(this article was very much helpful http://digistump.com/board/index.php?topic=2581.0 Many thanks to the commenters.)

Be sure to use subroutines defined in TrinketHidCombo.h. You cannot compile if you try to use the ones defined in TrinketMouse.h and TrinketKeyboard in same sketches.
