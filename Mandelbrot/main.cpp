// main.cpp : Defines the entry point for the console application.
// Basic application layout source from the following tutorial
// http://www.willusher.io/pages/sdl2/

#include "stdafx.h"

int main(int, char**) 
{
	//Initialise the Video Part of SDL2
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		//Print out an error message to the screen if this fails
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	//Creare a 800x800 window with the title Mandelbrot
	SDL_Window *window = SDL_CreateWindow("Mandlebrot", 100, 100, 800, 800, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		//Print out error if this fails
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}

	//Create a renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		//Print error and cleanup
		SDL_DestroyWindow(window);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	char * pixels = NULL;
	int pitch;
	SDL_Texture * mandlebrotTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, 800, 800);

	unsigned int format;

	// Get the size of the texture.
	int w, h;
	SDL_QueryTexture(mandlebrotTexture, &format, nullptr, &w, &h);
	//Controls the game loop
	bool quit = false;
	//Holds events coming from SDL
	SDL_Event event;
	//Game Loop, while quit is false
	while (!quit)
	{
		//Check for Messages from SDL
		while (SDL_PollEvent(&event)) {
			//quit is generated when red cross is clicked
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}

		//Clear the renderer
		SDL_RenderClear(renderer);
		SDL_PixelFormat pixelFormat;
		pixelFormat.format = format;
		Uint32 color = SDL_MapRGB(&pixelFormat, 1, 0, 0);
		//do drawing here
		SDL_LockTexture(mandlebrotTexture, NULL, (void**)&pixels, &pitch);



		for (int pixelY = 0; pixelY < 800; pixelY++) {
			for (int pixelX = 0; pixelX < 800; pixelX++){

				// Before setting the color, we need to know where we have to place it.
				unsigned int pixelPosition = pixelY * (pitch / sizeof(unsigned int)) + pixelX;

				// Now we can set the pixel(s) we want.
				pixels[pixelPosition] = color;
			}
		}

		SDL_UnlockTexture(mandlebrotTexture);

		SDL_RenderCopy(renderer, mandlebrotTexture, NULL, NULL);
		//Display the work the renderer has been doing, this make something appear on the screen
		SDL_RenderPresent(renderer);
	}

	//cleanup!
	SDL_DestroyTexture(mandlebrotTexture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}