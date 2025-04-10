# Antiquity

**Antiquity** is a lightweight browser built in C using **libcurl** for fetching web pages. The project is an exploration into building a basic web browser that can retrieve and display HTML content from any given URL. It’s an excellent exercise in working with **C** and **libcurl** to handle HTTP requests.

## Features
- Fetch web pages using `libcurl`.
- Simple memory handling for storing the fetched data.
- Modular design for easy extendability.

## Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/Rugwiroparfait/Antiquity.git
   cd Antiquity
   ```

2. **Install dependencies:**

   Make sure you have **libcurl** installed. You can install it using your package manager.

   On Ubuntu/Debian:

   ```bash
   sudo apt-get install libcurl4-openssl-dev
   ```

3. **Compile the project:**

   ```bash
   make
   ```

4. **Run the browser:**

   ```bash
   ./browser
   ```

   By default, the program fetches the URL `https://www.w3schools.com/` for demonstration.

## How It Works
- **libcurl** is used to fetch the URL.
- The fetched data is stored in dynamically allocated memory.
- A custom callback function handles the data chunk by chunk and stores it in a memory structure.

## Usage
To fetch a custom URL, you can modify the code in `main.c` to set your desired URL in the `fetch_url()` function call.

## Contributing

Feel free to contribute by opening issues or submitting pull requests.

## License

Distributed under the MIT License. See `LICENSE` for more information.

## Author

**Rugwiroparfait** – [GitHub](https://github.com/Rugwiroparfait)


