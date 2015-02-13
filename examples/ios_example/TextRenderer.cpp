#include <stdlib.h>
#import <OpenGLES/ES2/glext.h>
#include <SimpleText.h>
#include "TextRenderer.h"


SimpleText* k_simpleText;

void InitText()
{
	k_simpleText = new SimpleText;
}

void DrawSometext()
{
	k_simpleText->ResetFont();
	k_simpleText->RenderLabel("Example of using SimpleText library", 250, 10);
	
	k_simpleText->SetTextSize(SimpleText::SIZE_32);
	k_simpleText->RenderLabel("Variable font size", 10, 50);
	
	k_simpleText->SetTextSize(SimpleText::SIZE_64);
	k_simpleText->RenderLabel("Variable font size", 10, 80);
	
	k_simpleText->SetTextSize(SimpleText::SIZE_16);
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, 0, 100, 255, 255);
	k_simpleText->RenderLabel("Variable colors", 10, 160);
	
	k_simpleText->SetColorf(SimpleText::TEXT_COLOR, 1.0f, 0.1f, 0.7f);
	k_simpleText->RenderLabel("Variable colors", 150, 160);
	
	k_simpleText->SetColorf(SimpleText::TEXT_COLOR, 0.2f, 0.4f, 0.7f);
	k_simpleText->SetColorf(SimpleText::BACKGROUND_COLOR, 0.3f, 0.1f, 0.2f);
	k_simpleText->RenderLabel("Variable colors", 290, 160);
	
	k_simpleText->SetColorf(SimpleText::TEXT_COLOR, 0.8f, 0.1f, 0.4f);
	k_simpleText->SetColorf(SimpleText::BACKGROUND_COLOR, 0.2f, 0.7f, 0.5f);
	k_simpleText->RenderLabel("Variable colors      ", 430, 160);
	
	k_simpleText->SetColorf(SimpleText::TEXT_COLOR, 0.2f, 0.3f, 0.3f, 0.9f);
	k_simpleText->SetColorf(SimpleText::BACKGROUND_COLOR, 0.7f, 0.1f, 0.2f, 0.3f);
	k_simpleText->EnableBlending(true);
	k_simpleText->RenderLabel("Alpha blending", 570, 160);
	
	k_simpleText->ResetFont();
	
	k_simpleText->RenderLabel("Standard VGA colors:", 10, 180);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::RED);
	k_simpleText->RenderLabel("RED", 10, 200);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::GREEN);
	k_simpleText->RenderLabel("GREEN", 80, 200);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::YELLOW);
	k_simpleText->RenderLabel("YELLOW", 150, 200);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::BLUE);
	k_simpleText->RenderLabel("BLUE", 220, 200);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::MAGENTA);
	k_simpleText->RenderLabel("MAGENTA", 290, 200);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::CYAN);
	k_simpleText->RenderLabel("CYAN", 360, 200);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::WHITE);
	k_simpleText->RenderLabel("WHITE", 430, 200);
	
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::RED, SimpleText::BOLD);
	k_simpleText->RenderLabel("RED", 10, 220);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::GREEN, SimpleText::BOLD);
	k_simpleText->RenderLabel("GREEN", 80, 220);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::YELLOW, SimpleText::BOLD);
	k_simpleText->RenderLabel("YELLOW", 150, 220);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::BLUE, SimpleText::BOLD);
	k_simpleText->RenderLabel("BLUE", 220, 220);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::MAGENTA, SimpleText::BOLD);
	k_simpleText->RenderLabel("MAGENTA", 290, 220);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::CYAN, SimpleText::BOLD);
	k_simpleText->RenderLabel("CYAN", 360, 220);
	
	k_simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::WHITE, SimpleText::BOLD);
	k_simpleText->RenderLabel("WHITE", 430, 220);
	
	k_simpleText->ResetFont();
	
	k_simpleText->RenderLabel("Supports ANSI escape sequences for setting colors.", 10, 260);
	
	k_simpleText->RenderLabel("Thus, you can use codes 30+i to specify foreground color, 40+i to specify background color", 10, 280);
	
	k_simpleText->RenderLabel("For example, let's take this string:", 10, 300);
	
	k_simpleText->RenderLabel("\\033[32mGreen \\033[1;31mBold red \\033[22mNormal red \\033[1;34;47m Bold blue on white \\033[0mReset", 10, 320);
	
	k_simpleText->RenderLabel("\033[32mGreen \033[1;31mBold red \033[22mNormal red \033[1;34;47m Bold blue on white \033[0mReset", 10, 340);
}
