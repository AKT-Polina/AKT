import pygame
import sys

# Инициализация Pygame
pygame.init()

# Настройки экрана
WIDTH, HEIGHT = 800, 600
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Платформер")

#Фон
background = pygame.image.load('background.png')
background_width, background_height = background.get_size()
scaled_background = pygame.transform.scale(background, (WIDTH, HEIGHT))


# Цвета
WHITE = (255, 255, 255)
BLUE = (0, 0, 255)
PLATFORM_COLOR = (29, 171, 68)
BLACK = (0, 0, 0)

# Игрок
player_width, player_height = 70, 70
player_x, player_y = WIDTH // 2, HEIGHT - player_height 
player_speed = 5
player_jump_speed = 15
player_gravity = 1
player_velocity_y = 0
is_jumping = False

#Импорт изображаения
player_image = pygame.image.load('duck.png').convert_alpha()
scaled_image = pygame.transform.scale(player_image, (player_width, player_height))
# Платформы
platforms = [
    pygame.Rect(0, HEIGHT - 50, WIDTH, 50),  # Основная платформа
    pygame.Rect(200, 400, 200, 20),
    pygame.Rect(500, 300, 150, 20),
    pygame.Rect(100, 200, 150, 20),
]

# Основной игровой цикл
clock = pygame.time.Clock()
running = True

while running:
    screen.blit(scaled_background, (0, 0))

    # Обработка событий
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Управление игроком
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT] and player_x > 0:
        player_x -= player_speed
    if keys[pygame.K_RIGHT] and player_x < WIDTH - player_width:
        player_x += player_speed
    if keys[pygame.K_SPACE] and not is_jumping:
        is_jumping = True
        player_velocity_y = -player_jump_speed

    # Гравитация и прыжок
    player_rect = pygame.Rect(player_x, player_y, player_width, player_height)

    for platform in platforms:
            if not player_rect.colliderect(platform) and is_jumping != True:
                is_jumping = True
                break
    
    # если в прыжке
    if is_jumping:
        player_y += player_velocity_y
        player_velocity_y += player_gravity

        # Проверка столкновений с платформами
        
        for platform in platforms:
            if player_rect.colliderect(platform) and player_velocity_y > 0:
                is_jumping = False
                player_y = platform.y - player_height +1 
                player_velocity_y = 0
                break

        # Если игрок падает за пределы экрана
        if player_y > HEIGHT:
            player_y = HEIGHT - player_height
            is_jumping = False
            player_velocity_y = 0

    # Отрисовка платформ
    for platform in platforms:
        pygame.draw.rect(screen, PLATFORM_COLOR, platform)

    #отрисовка персонажа
    if keys[pygame.K_LEFT]:
        scaled_image = pygame.transform.scale(player_image, (player_width, player_height))
        scaled_image = pygame.transform.flip(scaled_image, True, False)  # Отражение по горизонтали
        screen.blit(scaled_image, (player_x, player_y))
    elif keys[pygame.K_RIGHT]:
        scaled_image = pygame.transform.scale(player_image, (player_width, player_height))
        screen.blit(scaled_image, (player_x, player_y))
    else:
        screen.blit(scaled_image, (player_x, player_y))

    for platform in platforms:
            if player_rect.colliderect(platform) and player_velocity_y > 0:
                print(" velocity 0 , colliding" )
                break

    
    # Обновление экрана
    pygame.display.flip()
    clock.tick(60)

# Завершение игры
pygame.quit()
sys.exit()
