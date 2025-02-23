# 🔎 WikiLadder - Wikipedia Pathfinding App
*A command-line application for finding the shortest path between Wikipedia articles.*

## 🚀 About the Project
WikiLadder is a **C++-based application** that finds the shortest path between two Wikipedia pages by following hyperlinks on each page. It demonstrates **graph traversal algorithms**, specifically **BFS (Breadth-First Search)**, to determine the shortest link chain between articles.

## 🔧 Features
- ✅ Finds the **shortest path** between any two Wikipedia articles.
- ✅ Implements **graph traversal** techniques to navigate links.
- ✅ Utilizes **libcurl** for fetching Wikipedia page contents.
- ✅ Includes **GoogleTest** for unit testing.
- ✅ Command-line interface for easy input/output.

## 🛠️ Tech Stack
- **Language:** C++
- **Libraries:** libcurl, GoogleTest
- **Build System:** CMake, Makefile
- **Algorithms:** Graph traversal (BFS)

## 🛠️ Setup & Installation
### 1️⃣ Clone the Repository
```bash
git clone https://github.com/blainesea/WikiLadder-Personal.git
cd WikiLadder-Personal
```
### 2️⃣ Install Dependencies
On Ubuntu/Debian:
```bash
sudo apt update && sudo apt install build-essential libcurl4-openssl-dev
```
On MacOS (Homebrew):
```bash
brew install curl
```
### 3️⃣ Build the Application
```bash
make  # Uses Makefile
```
Or using CMake:
```bash
mkdir build && cd build
cmake ..
make
```
### 4️⃣ Run the Program
```bash
./WikiLadder
```

## 🎯 My Contributions
As part of a team project, I contributed the following:
- **Implemented graph traversal logic (BFS) for Wikipedia link pathfinding.**
- **Developed core C++ modules** for parsing and handling page links.
- **Optimized performance** to improve search efficiency.

## 🤝 Acknowledgments
This project was built as part of a team with **[@sadieyoung10](https://github.com/sadieyoung10)**

## 🏆 Future Enhancements
- ✅ Improve Wikipedia scraping efficiency.
- ✅ Add **a web-based version** with a GUI.
- ✅ Implement **AI-driven path predictions**.

---

### 🔗 Connect With Me
💻 **GitHub:** [github.com/blainesea](https://github.com/blainesea)  
🌟 **LinkedIn:** [linkedin.com/in/blaineseaman](https://linkedin.com/in/blaineseaman)  
📧 **Email:** blaineseaman2001@gmail.com
