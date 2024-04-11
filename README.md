**cub3D Project**

**Introduction**

This repository contains my implementation of the cub3D graphics engine, a project from the 42 curriculum. cub3D is a raycasting engine that renders a 3D environment from a first-person perspective using pre-rendered 2D textures.

**Key Features**

*   **Raycasting Rendering:** Implements raycasting to accurately project 3D objects onto the 2D screen, creating a realistic sense of depth.
*   **Textured Walls and Floors:** Incorporates 2D textures to add visual detail and realism to the environment.
*   **Player Movement:** Enables the player to navigate the 3D world using keyboard controls (WASD for movement, mouse for rotation).
*   **Sprite Casting:** Renders 2D sprites (e.g., objects, enemies) onto the 3D scene, enhancing the visual complexity.
*   **Map Parsing:** Parses a provided map file (`.cub`) that defines the layout of the environment, including walls, textures, and object placement.
*   **Lighting and Color Effects:** Implements basic lighting effects to simulate light sources and shadows, improving the visual fidelity.
*   **Error Handling:** Includes robust error handling mechanisms to gracefully handle invalid map files or unexpected conditions.

**Technical Skills Demonstrated**

*   **C Programming:** Proficient use of C language constructs, including data structures, memory management, and algorithms.
*   **Graphics Programming:** In-depth understanding of raycasting principles, texture mapping, sprite casting, and 3D rendering techniques.
*   **File I/O:** Ability to read and parse map files effectively.
*   **Error Handling:** Implementation of error handling routines to ensure program stability.
*   **Project Management:** Well-organized code structure, clear documentation, and adherence to best practices.

**Installation**

1. Clone this repository.
2. Ensure you have the necessary development tools (e.g., GCC compiler) installed on your system.
3. Navigate to the project directory in your terminal.
4. Compile the project using `make`.
5. Run the executable (`cub3D`) with a valid map file as an argument (e.g., `./cub3D map.cub`).

**Usage**

*   Use the WASD keys to move the player around the environment.
*   Use the mouse to look around.
*   Additional controls may be implemented depending on features added (e.g., interact with objects, use items).
