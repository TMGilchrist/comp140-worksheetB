# comp140-worksheetB

## Game Proposal

### Overview
A 2D space flight simulator using top down "strafe and shoot" style game where you are pitted against waves of enemies in the bleak expanse of space.
Although the game is fairly conventional in its mechanical design, the controller input will be the unique selling point of the game.   

### Core Mechanics
* Top down shooter.  

### Input  
* Two axis of movement, forward and sideways, that can be combined for diagonal movement. Movement should be smooth and responsive. 
* A weapon that can be aimed independently of the ship movement. 360 degrees of aiming  
* For the prototype game, the keyboard will be used for ship movement (wasd) and the mouse will be used for aiming and shooting the weapon (look at cursor, mouse button to shoot).

### Player resources  
* Limited health bar protected by recharging shields.
* Shields will be equivilent to half of the player's health bar.
* Shield boost ability to quickly restore shields. Using a shield boost at full shields will double the player's maximum shields (does not stack with itself).
* Health-restoring pickups and shield boost pickups will spawn periodically to help keep the player alive and also provide points on interest for them to try and reach.

### Enemies  
* At least two enemy types.
* Basic Enemy will be a weak, slow moving enemy ship that fires single projectiles at a time.
* The Advanced enemy will be a faster moving ship that can fire two projectiles at a time for more damage.
* Further enemy types could be added as stretch goals.
* Enemies should spawn in roughly defined waves with short periods in between where shields can recharge and the player can take a breath.
* For clarity, "Wave" refers to a period of time where a group of enemies spawn simultaneously (or at roughly the same time) and then no more enemies spawn during that time period until the player has defeated all enemies. Once the player has defeated a wave, the next wave will occur, and so on.

### Possible Alternatives/Stretch Goals
* Two player co-op in which one player controls the ship movement and another player controls the weapon aiming. 
* Could be scaled up for multiple weapons.
* Shield mechanics could be expanded on to give the pilot more tactical options.
* Different weapon modes (high power-single shot; low power-spread shot; etc.) to give non-pilot players more tactical options.

## Controller Proposal
The Impractical and Dangerous Chair Joystick MK1

A computer chair (must have forward/backwards tilt, rotation, back adjustment) will act as the controller.  

* Forwards/backwards tilt will control forwards/backwards movement.
* Spinning the chair will control sideways movement.
* Some form of thumbstick for 360 degree aiming and shooting. (Possible alternative below)
* Back adjustment used to engage shield boost.
* It will probably require at least one accelerometer.

### Alternatives
* Alternative co-op would use a second chair to control the weapons aiming and firing. The weapon chairs would need a way to see the screen while spinning.
* Arm-rests controls to strafe? Spin chair 360 degrees to dodge.

