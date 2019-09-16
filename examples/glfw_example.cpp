#include <GL/gl3w.h>
#include <GLFW/glfw3.h>
#include <simpletext.h>
#include <stdio.h>

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(800, 600, "Simple Text", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (gl3wInit()) {
		fprintf(stderr, "failed to initialize OpenGL\n");
		return -1;
	}
	if (!gl3wIsSupported(3, 2)) {
		fprintf(stderr, "OpenGL 3.2 not supported\n");
		return -1;
	}
	printf("OpenGL %s, GLSL %s\n", glGetString(GL_VERSION),
		glGetString(GL_SHADING_LANGUAGE_VERSION));

	SimpleText* simpleText = new SimpleText;

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.0, 0.0, 0.0, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		simpleText->ResetFont();
		simpleText->SetCurrentViewport();

		simpleText->Label("Example of using SimpleText library", 250, 10);

		simpleText->ResetFont();
		simpleText->Label("Example of using SimpleText library", 250, 10);

		simpleText->SetTextSize(SimpleText::SIZE_32);
		simpleText->Label("Variable font size", 10, 50);

		simpleText->SetTextSize(SimpleText::SIZE_64);
		simpleText->Label("Variable font size", 10, 80);

		simpleText->SetTextSize(SimpleText::SIZE_16);
		simpleText->SetColor(SimpleText::TEXT_COLOR, 0, 100, 255, 255);
		simpleText->Label("Variable colors", 10, 160);

		simpleText->SetColorf(SimpleText::TEXT_COLOR, 1.0f, 0.1f, 0.7f);
		simpleText->Label("Variable colors", 150, 160);

		simpleText->SetColorf(SimpleText::TEXT_COLOR, 0.2f, 0.4f, 0.7f);
		simpleText->SetColorf(SimpleText::BACKGROUND_COLOR, 0.3f, 0.1f, 0.2f);
		simpleText->Label("Variable colors", 290, 160);

		simpleText->SetColorf(SimpleText::TEXT_COLOR, 0.8f, 0.1f, 0.4f);
		simpleText->SetColorf(SimpleText::BACKGROUND_COLOR, 0.2f, 0.7f, 0.5f);
		simpleText->Label("Variable colors      ", 430, 160);

		simpleText->SetColorf(SimpleText::TEXT_COLOR, 0.2f, 0.3f, 0.3f, 0.9f);
		simpleText->SetColorf(SimpleText::BACKGROUND_COLOR, 0.7f, 0.1f, 0.2f, 0.3f);
		simpleText->EnableBlending(true);
		simpleText->Label("Alpha blending", 570, 160);

		simpleText->ResetFont();

		simpleText->Label("Standard VGA colors:", 10, 180);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::RED);
		simpleText->Label("RED", 10, 200);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::GREEN);
		simpleText->Label("GREEN", 80, 200);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::YELLOW);
		simpleText->Label("YELLOW", 150, 200);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::BLUE);
		simpleText->Label("BLUE", 220, 200);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::MAGENTA);
		simpleText->Label("MAGENTA", 290, 200);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::CYAN);
		simpleText->Label("CYAN", 360, 200);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::WHITE);
		simpleText->Label("WHITE", 430, 200);


		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::RED, SimpleText::BOLD);
		simpleText->Label("RED", 10, 220);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::GREEN, SimpleText::BOLD);
		simpleText->Label("GREEN", 80, 220);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::YELLOW, SimpleText::BOLD);
		simpleText->Label("YELLOW", 150, 220);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::BLUE, SimpleText::BOLD);
		simpleText->Label("BLUE", 220, 220);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::MAGENTA, SimpleText::BOLD);
		simpleText->Label("MAGENTA", 290, 220);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::CYAN, SimpleText::BOLD);
		simpleText->Label("CYAN", 360, 220);

		simpleText->SetColor(SimpleText::TEXT_COLOR, SimpleText::WHITE, SimpleText::BOLD);
		simpleText->Label("WHITE", 430, 220);

		simpleText->ResetFont();

		simpleText->Label("Supports ANSI escape sequences for setting colors.", 10, 260);

		simpleText->Label("Thus, you can use codes 30+i to specify foreground color, 40+i to specify background color", 10, 280);

		simpleText->Label("For example, let's take this string:", 10, 300);

		simpleText->Label("\\033[32mGreen \\033[1;31mBold red \\033[22mNormal red \\033[1;34;47m Bold blue on white \\033[0mReset", 10, 320);

		simpleText->Label("\033[32mGreen \033[1;31mBold red \033[22mNormal red \033[1;34;47m Bold blue on white \033[0mReset", 10, 340);

		simpleText->Render();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	delete simpleText;

	glfwTerminate();
	return 0;
}