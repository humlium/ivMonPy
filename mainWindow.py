import sys, pygame
#pygame.font.init()
pygame.init()
size = 800, 480
screen = pygame.display.set_mode(size)

background = pygame.Surface(screen.get_size())
background = background.convert()
background.fill((255, 255, 255))

surface = pygame.Surface((100, 100))
image = pygame.image.load('main.png')
button = pygame.image.load('button.png')
circle = pygame.image.load('circle.png')

font = pygame.font.Font(None, 36)
text = font.render("Hello, World", 1, (255, 0, 0))
textPos = text.get_rect(centerx = background.get_width()//2, centery = background.get_height()//2)
background.blit(text, textPos)
screen.blit(background, background.get_rect())
screen.blit(image, (0, 0))
screen.blit(button, (10, 10))
screen.blit(circle, (30, 30))
pygame.display.flip()
while 1:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            sys.exit()
