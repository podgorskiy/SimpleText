#import "ViewController.h"
#import <OpenGLES/ES2/glext.h>

#include "TextRenderer.h"

@interface ViewController ()
{
	
}

@property (strong, nonatomic) EAGLContext *context;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];

    if (!self.context) {
        NSLog(@"Failed to create ES context");
    }
    
    GLKView *view = (GLKView *)self.view;
    view.context = self.context;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
	
	[EAGLContext setCurrentContext:self.context];
	
	InitText();
}

- (void)dealloc
{
	[EAGLContext setCurrentContext:self.context];
	
    if ([EAGLContext currentContext] == self.context) {
        [EAGLContext setCurrentContext:nil];
    }
}

- (BOOL)prefersStatusBarHidden {
    return YES;
}

- (void)glkView:(GLKView *)view drawInRect:(CGRect)rect
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawSometext();	
}

@end
