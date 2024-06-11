<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a name="readme-top"></a>
<!-- -->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Kawoogie/debounce_interrupt">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

<h3 align="center">Library to debounce inputs for the Mbed OS.</h3>

  <p align="center">
    This code debounces inputs for the Mbed OS. It has interrupt functionality built into the debouncing function. Written for Mbed OS 6.16. Examples are written for the MAX32630FTHR.
    <br />
    <a href="https://github.com/Kawoogie/debounce_interrupt"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Kawoogie/debounce_interrupt">View Demo</a>
    ·
    <a href="https://github.com/Kawoogie/debounce_interrupt/issues">Report Bug</a>
    ·
    <a href="https://github.com/Kawoogie/debounce_interrupt/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>    
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project
DebounceLib is an Mbed OS library for debouncing switches. It provides a simple way to debounce a switch connected to a specified pin and triggers a callback function when the switch state changes and remains stable for a specified debounce time.
- Debounces a switch connected to a specified pin. 
- Triggers a callback function when the switch state is stable. - Configurable debounce time.

- The `DebounceIntrptLib.h` and `DebounceIntrptLib.cpp` files contain the split library code with detailed Doxygen-style comments. 
- The `README.md` file provides a description of the library, installation instructions, usage example, API documentation, and license information, formatted for posting on GitHub.
<p align="right">(<a href="#readme-top">back to top</a>)</p>




<!-- GETTING STARTED -->
## Getting Started

To use this library, include the `DebounceIntrptLib.h` and `DebounceIntrptLib.cpp` files in your Mbed OS project. This is easiest done importing as a library.

### Prerequisites
This code is written for Mbed OS 6.16.
This code needs to be compiled using ARM KEIL Studio Cloud or Mbed Studio.
   ```

### Installation
This code can be imported to Mbed Studio by selecting Import Program under the File menu. When prompted, copy and paste the URL for this project into the Import Project pop-up.
The code needs to be compiled into a binary file, then uploaded to the microcontroller using a bootloader.
This code was tested on a MAX32630FTHR and a MAX32625PICO.

   ```

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage
Here's an example of how to use the DebounceintrptLib library to debounce a button and toggle an LED on and off using interrupts. 
### Example 
```cpp #include "mbed.h" #include "DebounceIntrptLib.h" // LED to indicate the state DigitalOut led(LED1); // Function to toggle the LED void toggle_led() { led = !led; } // Create debounce instance for P5_7 with a debounce time of 50 ms DebounceLib debounce(P5_7, 50, toggle_led); int main() { // Initially turn off the LED led = 0; // Main loop does nothing, as all work is done in interrupts while (true) { ThisThread::sleep_for(1000ms); // Sleep to reduce CPU usage } }

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/Kawoogie/debounce_interrupt/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->
## License

Distributed under the GPL-3.0 License. See `LICENSE.txt` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact
Project Link: [https://github.com/Kawoogie/debounce_interrupt](https://github.com/Kawoogie/debounce_interrupt)

<p align="right">(<a href="#readme-top">back to top</a>)</p>






<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/Kawoogie/debounce_interrupt.svg?style=for-the-badge
[contributors-url]: https://github.com/Kawoogie/debounce_interrupt/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/Kawoogie/debounce_interrupt.svg?style=for-the-badge
[forks-url]: https://github.com/Kawoogie/debounce_interrupt/network/members
[stars-shield]: https://img.shields.io/github/stars/Kawoogie/debounce_interrupt.svg?style=for-the-badge
[stars-url]: https://github.com/Kawoogie/debounce_interrupt/stargazers
[issues-shield]: https://img.shields.io/github/issues/Kawoogie/debounce_interrupt.svg?style=for-the-badge
[issues-url]: https://github.com/Kawoogie/debounce_interrupt/issues
[license-shield]: https://img.shields.io/github/license/Kawoogie/debounce_interrupt.svg?style=for-the-badge
[license-url]: https://github.com/Kawoogie/debounce_interrupt/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/lee-sikstrom-a6472a113
[product-screenshot]: images/screenshot.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white
[Next-url]: https://nextjs.org/
[React.js]: https://img.shields.io/badge/React-20232A?style=for-the-badge&logo=react&logoColor=61DAFB
[React-url]: https://reactjs.org/
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[Vue-url]: https://vuejs.org/
[Angular.io]: https://img.shields.io/badge/Angular-DD0031?style=for-the-badge&logo=angular&logoColor=white
[Angular-url]: https://angular.io/
[Svelte.dev]: https://img.shields.io/badge/Svelte-4A4A55?style=for-the-badge&logo=svelte&logoColor=FF3E00
[Svelte-url]: https://svelte.dev/
[Laravel.com]: https://img.shields.io/badge/Laravel-FF2D20?style=for-the-badge&logo=laravel&logoColor=white
[Laravel-url]: https://laravel.com
[Bootstrap.com]: https://img.shields.io/badge/Bootstrap-563D7C?style=for-the-badge&logo=bootstrap&logoColor=white
[Bootstrap-url]: https://getbootstrap.com
[JQuery.com]: https://img.shields.io/badge/jQuery-0769AD?style=for-the-badge&logo=jquery&logoColor=white
[JQuery-url]: https://jquery.com
