import pygame
import random
import time

# --- Game Constants and Setup ---

# Window dimensions
WINDOW_WIDTH = 720
WINDOW_HEIGHT = 480

# Colors (R, G, B)
BLACK = (0, 0, 0)
WHITE = (255, 255, 255)
RED = (255, 0, 0)
GREEN = (0, 255, 0)
BLUE = (0, 0, 255)

# Game speed
SNAKE_SPEED = 15

# Initialize Pygame
pygame.init()
pygame.display.set_caption('Python Snake Game')
game_window = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))

# FPS (Frames Per Second) controller
fps_controller = pygame.time.Clock()

# --- Game Variables ---

# Snake default position and body
snake_position = [100, 50]
snake_body = [
    [100, 50],
    [90, 50],
    [80, 50]
]

# Food position
fruit_position = [
    random.randrange(1, (WINDOW_WIDTH // 10)) * 10,
    random.randrange(1, (WINDOW_HEIGHT // 10)) * 10
]
fruit_spawn = True

# Setting default snake direction
direction = 'RIGHT'
change_to = direction

score = 0

# --- Functions ---

# Function to display the score
def show_score(choice, color, font, size):
    score_font = pygame.font.SysFont(font, size)
    score_surface = score_font.render('Score : ' + str(score), True, color)
    score_rect = score_surface.get_rect()
    if choice == 1:
        score_rect.midtop = (WINDOW_WIDTH / 10, 15)
    else:
        score_rect.midtop = (WINDOW_WIDTH / 2, WINDOW_HEIGHT / 1.25)
    game_window.blit(score_surface, score_rect)

# Game Over function
def game_over():
    game_over_font = pygame.font.SysFont('times new roman', 50)
    game_over_surface = game_over_font.render('Your Score is : ' + str(score), True, RED)
    game_over_rect = game_over_surface.get_rect()
    game_over_rect.midtop = (WINDOW_WIDTH / 2, WINDOW_HEIGHT / 4)
    game_window.blit(game_over_surface, game_over_rect)
    pygame.display.flip()
    time.sleep(2)  # Wait 2 seconds before quitting
    pygame.quit()
    quit()

# --- Main Game Loop ---

while True:
    # Handle user events (keyboard presses)
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            quit()
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                change_to = 'UP'
            elif event.key == pygame.K_DOWN:
                change_to = 'DOWN'
            elif event.key == pygame.K_LEFT:
                change_to = 'LEFT'
            elif event.key == pygame.K_RIGHT:
                change_to = 'RIGHT'

    # Validate the direction change (preventing the snake from reversing)
    if change_to == 'UP' and direction != 'DOWN':
        direction = 'UP'
    if change_to == 'DOWN' and direction != 'UP':
        direction = 'DOWN'
    if change_to == 'LEFT' and direction != 'RIGHT':
        direction = 'LEFT'
    if change_to == 'RIGHT' and direction != 'LEFT':
        direction = 'RIGHT'

    # Move the snake
    if direction == 'UP':
        snake_position[1] -= 10
    if direction == 'DOWN':
        snake_position[1] += 10
    if direction == 'LEFT':
        snake_position[0] -= 10
    if direction == 'RIGHT':
        snake_position[0] += 10

    # Grow the snake's body
    snake_body.insert(0, list(snake_position))

    # Check for collision with food
    if snake_position[0] == fruit_position[0] and snake_position[1] == fruit_position[1]:
        score += 10
        fruit_spawn = False
    else:
        # Remove the last segment if no food is eaten
        snake_body.pop()

    # Re-spawn food
    if not fruit_spawn:
        fruit_position = [
            random.randrange(1, (WINDOW_WIDTH // 10)) * 10,
            random.randrange(1, (WINDOW_HEIGHT // 10)) * 10
        ]
    fruit_spawn = True

    # Clear the screen
    game_window.fill(BLACK)

    # Draw the snake and fruit
    for pos in snake_body:
        pygame.draw.rect(game_window, GREEN, pygame.Rect(pos[0], pos[1], 10, 10))
    pygame.draw.rect(game_window, WHITE, pygame.Rect(fruit_position[0], fruit_position[1], 10, 10))

    # Check for boundary collisions
    if snake_position[0] < 0 or snake_position[0] > WINDOW_WIDTH - 10:
        game_over()
    if snake_position[1] < 0 or snake_position[1] > WINDOW_HEIGHT - 10:
        game_over()

    # Check for self-collision
    for block in snake_body[1:]:
        if snake_position[0] == block[0] and snake_position[1] == block[1]:
            game_over()

    # Display the score
    show_score(1, WHITE, 'consolas', 20)

    # Update the display
    pygame.display.update()

    # Control the game speed
    fps_controller.tick(SNAKE_SPEED)