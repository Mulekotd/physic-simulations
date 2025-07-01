# Physics Simulation

## 📌 Overview

A C++ physics simulation project using modern OpenGL (GLFW) for real-time visualization of particles and fields. The system is modular, supporting extensible simulation laws (Newton's Laws), and is designed for future integration with ImGui for interactive UI controls.

## 🛠️ Selected Technologies

### 1. C++ 17

The main programming language, chosen for its performance and modern features, enabling efficient simulation and extensible architecture.

![C++](https://upload.wikimedia.org/wikipedia/commons/1/18/ISO_C%2B%2B_Logo.svg)

---

### 2. OpenGL (GLFW)

Used for rendering the simulation in real time, handling window/context creation, and drawing particles and fields.

![OpenGL](https://opengl.org/img/opengl_logo.png)

![GLFW](https://cdn-b.saashub.com/images/app/service_logos/38/b48cc85cebb2/large.png?1553244024)

---

### 3. CMake

Build system generator for cross-platform compilation and easy dependency management.

![CMake](https://upload.wikimedia.org/wikipedia/commons/1/13/Cmake.svg)

---

### 4. ImGui

Immediate Mode GUI library for C++ to provide interactive controls and visualization.

![ImGui](https://blog.conan.io/assets/post_images/2019-06-26/conan-imgui-triangle-rotate-color.gif)

---

## ⚙️ Installation and Setup

### 1. Clone the Repository

Clone this repository to your local environment:

```bash
git clone --recurse-submodules https://github.com/Mulekotd/physics-simulation.git
cd physics-simulation
```

### 2. Install Dependencies

Make sure you have the following installed on your system:

- C++17 compatible compiler (e.g., g++ 9+)
- CMake 3.10+
- OpenGL development libraries
- GLFW 3.x

On Ubuntu/Debian:

```bash
sudo apt update
sudo apt install build-essential cmake libglfw3-dev libgl1-mesa-dev
```

### 3. Build the Project

```bash
mkdir build
cd build
cmake ..
make
```

### 4. Run the Simulation

```bash
./physics-simulation
```

---

## 🤝 Feedback and Contributions

Feedback, suggestions, and contributions are welcome!  
If you have ideas for improvements or encounter any issues, please [open an issue](https://github.com/Mulekotd/physics-simulation/issues) on GitHub.
