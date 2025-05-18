# MyDefender - Tower Defense Game

A strategic tower defense game built with CSFML (Simple and Fast Multimedia Library for C). Defend your territory by strategically placing and upgrading towers to stop waves of enemies.

## Project Overview

MyDefender is a feature-rich tower defense game that includes:
- Multiple tower types and upgrade paths
- Different enemy types with unique behaviors
- Resource management system
- Wave-based gameplay
- Interactive UI and menus
- Sound effects and background music
- Score tracking system

## Project Structure

```
MyDefender/
├── src/
│   ├── my_game/           # Core gameplay logic
│   ├── menu_gestion/      # Menu system management
│   ├── display_gestion/   # Graphics rendering
│   ├── endgame_gestion/   # Game over handling
│   ├── structures_gestion/# Data structure management
│   ├── my_defender.c      # Main game loop
│   └── main.c            # Program entry point
├── png/                  # Game assets
│   ├── towers/          # Tower sprites
│   ├── enemies/         # Enemy sprites
│   ├── ui/              # UI elements
│   └── maps/            # Map textures
├── music_sounds/        # Audio assets
├── font/               # Game fonts
├── include/            # Header files
└── lib/               # Library files
```

## Game Features

### Towers
- 4 unique tower types (Tier 1-4)
- Upgrade system
- Different attack patterns
- Strategic placement options

### Enemies
- Multiple enemy types
- Varied movement patterns
- Increasing difficulty
- Wave-based spawning

### Economy System
- Resource management
- Tower costs
- Upgrade expenses
- Wave rewards

### Game Modes
- Main campaign
- Survival mode
- Score-based challenges

## Dependencies

- CSFML Library (Simple and Fast Multimedia Library for C)
- C compiler (gcc recommended)
- Make build system

## Building the Project

To compile the game:

```bash
make
```

This will generate the `my_defender` executable.

## Playing the Game

### Starting the Game

```bash
./my_defender
```

### Controls

- **Left Click**: Place towers, interact with UI
- **Right Click**: Cancel selection/action
- **Escape**: Pause game
- **Space**: Start wave (when available)
- **1-4**: Quick select tower types
- **U**: Upgrade selected tower
- **S**: Sell selected tower

### Game Interface

1. **Main Menu**
   - Play game
   - Settings
   - Scoreboard
   - Quit

2. **In-Game HUD**
   - Resources display
   - Wave information
   - Health points
   - Score counter
   - Tower selection panel

3. **Pause Menu**
   - Resume game
   - Restart level
   - Settings
   - Return to main menu

4. **Settings**
   - Volume controls
   - Music toggle
   - Sound effects toggle

## Implementation Details

The game features:
- Wave management system
- Pathfinding for enemies
- Tower targeting algorithms
- Resource management
- Score calculation
- Save/Load system
- Sound management
- State machine for game flow

## Technical Features

- Efficient collision detection
- Memory management
- Event handling system
- Animation system
- Particle effects
- Sound mixing

## Building and Cleaning

Available make targets:
- `make`: Build the game
- `make clean`: Remove object files
- `make fclean`: Remove object files and executable
- `make re`: Rebuild the project

## License

This project is licensed under the terms provided in the LICENSE file.

## Contributing

Contributions are welcome! Feel free to submit issues and pull requests.

## Credits

- CSFML Library for graphics and audio
- Custom artwork and animations
- Sound effects and music
- Font resources 