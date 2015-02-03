#include <SDL.h>
#include <SDL_opengl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <emscripten.h>

#define SIMPLE_TEXT_PRINT_ERROR(...) printf(__VA_ARGS__)

#include <simpletext.h>

void Init(void*);
void loop();

SimpleText* simpleText;

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
	}

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); 

	int height = 600;
	int width = 800;
	
	SDL_Surface *screen = SDL_SetVideoMode(width, height, 16, SDL_OPENGL); 
	if (!screen) {
		printf("Unable to set video mode: %s\n", SDL_GetError());
	}
	
	emscripten_async_call(Init, NULL, 1000);
}

void Init(void*)
{
	simpleText = new SimpleText;
	emscripten_set_main_loop(loop, 0, 0);
}

void loop()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
	}

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	simpleText->ResetFont();
	simpleText->RenderLabel("Example of using SimpleText library", 250, 10);

	simpleText->SetTextSize(SimpleText::SIZE_32);
	simpleText->RenderLabel("Variable font size", 10, 50);

	simpleText->SetTextSize(SimpleText::SIZE_64);
	simpleText->RenderLabel("Variable font size", 10, 80);

	simpleText->SetTextSize(SimpleText::SIZE_16);
	simpleText->SetColor(SimpleText::TEXT_COLOR, 0, 100, 255, 255);
	simpleText->RenderLabel("Variable colors", 10, 160);

	simpleText->SetColorf(SimpleText::TEXT_COLOR, 1.0f, 0.1f, 0.7f);
	simpleText->RenderLabel("Variable colors", 150, 160);

	simpleText->SetColorf(SimpleText::TEXT_COLOR, 0.2f, 0.4f, 0.7f);
	simpleText->SetColorf(SimpleText::BACKGROUND_COLOR, 0.3f, 0.1f, 0.2f);
	simpleText->RenderLabel("Variable colors", 290, 160);

	simpleText->SetColorf(SimpleText::TEXT_COLOR, 0.8f, 0.1f, 0.4f);
	simpleText->SetColorf(SimpleText::BACKGROUND_COLOR, 0.2f, 0.7f, 0.5f);
	simpleText->RenderLabel("Variable colors      ", 430, 160);

	simpleText->SetColorf(SimpleText::TEXT_COLOR, 0.2f, 0.3f, 0.3f, 0.9f);
	simpleText->SetColorf(SimpleText::BACKGROUND_COLOR, 0.7f, 0.1f, 0.2f, 0.3f);
	simpleText->EnableBlending(true);
	simpleText->RenderLabel("Alpha blending", 570, 160);

	simpleText->ResetFont();

	simpleText->RenderLabel("Standard VGA colors:", 10, 180);
		
	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::RED);
	simpleText->RenderLabel("RED", 10, 200);

	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::GREEN);
	simpleText->RenderLabel("GREEN", 80, 200);

	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::YELLOW);
	simpleText->RenderLabel("YELLOW", 150, 200);

	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::BLUE);
	simpleText->RenderLabel("BLUE", 220, 200);

	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::MAGENTA);
	simpleText->RenderLabel("MAGENTA", 290, 200);

	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::CYAN);
	simpleText->RenderLabel("CYAN", 360, 200);

	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::WHITE);
	simpleText->RenderLabel("WHITE", 430, 200);


	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::RED, SimpleText::BOLD);
	simpleText->RenderLabel("RED", 10, 220);

	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::GREEN, SimpleText::BOLD);
	simpleText->RenderLabel("GREEN", 80, 220);

	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::YELLOW, SimpleText::BOLD);
	simpleText->RenderLabel("YELLOW", 150, 220);

	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::BLUE, SimpleText::BOLD);
	simpleText->RenderLabel("BLUE", 220, 220);

	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::MAGENTA, SimpleText::BOLD);
	simpleText->RenderLabel("MAGENTA", 290, 220);

	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::CYAN, SimpleText::BOLD);
	simpleText->RenderLabel("CYAN", 360, 220);

	simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::WHITE, SimpleText::BOLD);
	simpleText->RenderLabel("WHITE", 430, 220);

	simpleText->ResetFont();

	simpleText->RenderLabel("Supports ANSI escape sequences for setting colors.", 10, 260);

	simpleText->RenderLabel("Thus, you can use codes 30+i to specify foreground color, 40+i to specify background color", 10, 280);

	simpleText->RenderLabel("For example, let's take this string:", 10, 300);
	
	simpleText->RenderLabel("\\033[32mGreen \\033[1;31mBold red \\033[22mNormal red \\033[1;34;47m Bold blue on white \\033[0mReset", 10, 320);

	simpleText->RenderLabel("\033[32mGreen \033[1;31mBold red \033[22mNormal red \033[1;34;47m Bold blue on white \033[0mReset", 10, 340);
	
	SDL_GL_SwapBuffers();
}
