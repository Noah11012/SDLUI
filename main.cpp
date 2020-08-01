#include "SDL.h"
#include "ui.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("SDLUI app", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
    SDLUI_Init(renderer, window);
	bool quit = false;
    SDL_Event e;
    
#include "demo_controls.cpp"
    
    while (!quit)
    {
        while (SDL_PollEvent(&e))
	    {
            if (e.type == SDL_QUIT)
	        {
	            quit = true;
	        }
            
            if(e.type == SDL_MOUSEBUTTONDOWN || e.type == SDL_MOUSEBUTTONUP)
            {
                SDLUI_MouseStateSet(e.type, e.button.button);
            }
            if(e.type == SDL_KEYDOWN)
            {
                if(e.key.keysym.sym == SDLK_RETURN)
                {
                    wnd->visible = !wnd->visible;
                }
            }
        }
        
        if(SDLUI_Window(wnd))
        {
            
        }
        if(SDLUI_Button(btn))
        {
            
        }
        if(SDLUI_SliderInt(si))
        {
            
        }
        if(SDLUI_CheckBox(chk))
        {
            
        }
        if(SDLUI_ToggleButton(tb))
        {
            
        }
        
        SDLUI_RadioButton(rb1);
        SDLUI_RadioButton(rb2);
        SDLUI_RadioButton(rb3);
        
        SDLUI_RadioButton(rb4);
        SDLUI_RadioButton(rb5);
        SDLUI_RadioButton(rb6);
        
        SDLUI_Window(wnd2);
        
        SDL_SetRenderDrawColor(renderer, 60, 60, 60, 255);
        SDL_RenderClear(renderer);
        SDLUI_Render();
        SDL_RenderPresent(renderer);
    }
    
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
	return 0;
}