import random
import protocol as pp
import requests

pp.infotext = 'name="pbrain-trombia", authors="Lunnos, 0yco, Edgar", version="1.0", country="France", www="https://github.com/EpitechPromo2026/B-AIA-500-MPL-5-1-gomoku-loic.tisseyre"'

DEBUG_MODE = False # set to True to enable debug messages
MAX_BOARD = 100
board = [[0 for i in range(MAX_BOARD)] for j in range(MAX_BOARD)]

def send_debug_message(message):
    if DEBUG_MODE:
        payload = {"content": message}
        requests.post("https://discord.com/api/webhooks/1173653960305954967/-X4q-HRvHqLTorf0w8lVB8ppsHLUqGfOGKmeBxaZxIg9558kfMh99-mDEbdhouEhb2HF", json=payload)

def brain_init():
    send_debug_message('``` ```\n> **Initialisation de Sofia Falcou 🤖**\n---------------------------------------')
    if pp.size < 5:
        pp.pipeOut("ERROR size of the board")
        return
    if pp.size > MAX_BOARD:
        pp.pipeOut("ERROR Maximal board size is {}".format(MAX_BOARD))
        return
    pp.pipeOut("OK")

def brain_restart():
    send_debug_message('> **Reinitialisation de Sofia Falcou 🤖**\n---------------------------------------')
    for x in range(pp.size):
        for y in range(pp.size):
            board[x][y] = 0
    pp.pipeOut("OK")

def isFree(x, y):
    return x >= 0 and y >= 0 and x < pp.size and y < pp.size and board[x][y] == 0

def brain_my(x, y):
    if isFree(x,y):
        board[x][y] = 1
    else:
        pp.pipeOut("ERROR my move [{},{}]".format(x, y))

def brain_opponents(x, y):
    if isFree(x,y):
        board[x][y] = 2
        send_debug_message("Opponent played at {},{}".format(x,y))
        return True
    else:
        pp.pipeOut("ERROR opponents's move [{},{}]".format(x, y))
        return False

def brain_block(x, y):
    if isFree(x,y):
        board[x][y] = 3
        send_debug_message("I blocked at {},{}".format(x,y))
    else:
        pp.pipeOut("ERROR winning move [{},{}]".format(x, y))

def brain_takeback(x, y):
    if x >= 0 and y >= 0 and x < pp.size and y < pp.size and board[x][y] != 0:
        board[x][y] = 0
        return 0
    return 2

def brain_turn():
    if pp.terminateAI:
        return

    x, y = algo()
    pp.do_mymove(x, y)

def algo():
    # Si le score peut me faire gagner, jouer ce coup
    best_move = find_winning_offensive_move()
    if best_move is not None:
        send_debug_message("DEBUG : Winning move")
        return best_move

    # Vérifier pour chaque case du plateau pour le blocage
    for x in range(pp.size):
        for y in range(pp.size):
            if can_block(x, y):
                send_debug_message("DEBUG : Defensive move")
                return x, y

    # Si aucun blocage nécessaire, chercher le meilleur coup offensif
    best_move = find_best_offensive_move()
    if best_move:
        send_debug_message("DEBUG : Offensive move")
        return best_move

    # Si aucune opportunité offensive, jouer un coup aléatoire
    while True:
        x = random.randint(0, pp.size - 1)
        y = random.randint(0, pp.size - 1)
        if isFree(x, y):
            return x, y



###### WINNING MOVE ######
def find_winning_offensive_move():
    for x in range(pp.size):
        for y in range(pp.size):
            if isFree(x, y) and evaluate_winning_position(x, y) >= 4:
                return (x, y)  # Retourner la position du coup gagnant
    return None  # Aucun coup gagnant trouvé

def evaluate_winning_position(x, y):
    directions = [(1, 0), (0, 1), (1, 1), (1, -1)]  # Horizontal, Vertical, Diagonal droite, Diagonal gauche
    for dx, dy in directions:
        if evaluate_line(x, y, dx, dy, 1) == 4:  # Chercher quatre pierres alignées de l'IA
            return 4
    return 0

def evaluate_line(x, y, dx, dy, player):
    count = 0
    sequence = []

    # Explorer la ligne dans une direction
    for i in range(-4, 5):
        nx, ny = x + dx * i, y + dy * i
        if 0 <= nx < pp.size and 0 <= ny < pp.size:
            sequence.append(board[nx][ny])
        else:
            sequence.append(-1)

    # Compter les pierres de l'IA dans la séquence
    for i in range(len(sequence) - 4):
        window = sequence[i:i+5]
        if window.count(player) == 4 and window.count(0) == 1:
            count = 4  # Quatre pierres de l'IA avec un espace libre pour gagner
            break

    return count
###### WINNING MOVE ######



###### DEFENSIVE MOVE ######
def can_block(x, y):
    if not isFree(x, y):
        return False

    directions = [(1, 0), (0, 1), (1, 1), (1, -1)]  # Horizontal, Vertical, Diagonal droite, Diagonal gauche
    for dx, dy in directions:
        if check_line(x, y, dx, dy, 2):
            return True
    return False

def check_line(x, y, dx, dy, player):
    count = 0
    spaces = []

    # Vérifier les pierres du joueur dans une direction
    for i in range(1, 5):
        nx, ny = x + dx * i, y + dy * i
        if 0 <= nx < pp.size and 0 <= ny < pp.size:
            if board[nx][ny] == player:
                count += 1
            elif board[nx][ny] == 0:
                spaces.append((nx, ny))
                break
            else:
                break

    # Vérifier dans la direction opposée
    for i in range(1, 5):
        nx, ny = x - dx * i, y - dy * i
        if 0 <= nx < pp.size and 0 <= ny < pp.size:
            if board[nx][ny] == player:
                count += 1
            elif board[nx][ny] == 0:
                spaces.append((nx, ny))
                break
            else:
                break

    # Bloquer si trois pierres avec un espace ouvert, ou quatre avec un espace à une extrémité
    if count == 3 and len(spaces) == 2:
        return spaces[0]  # Bloquer un côté de trois pierres
    elif count == 4 and len(spaces) > 0:
        return spaces[0]  # Bloquer l'extrémité ouverte des quatre pierres

    return False
###### DEFENSIVE MOVE ######



###### OFFENSIVE MOVE ######
def find_best_offensive_move():
    best_score = 0
    best_move = None
    for x in range(pp.size):
        for y in range(pp.size):
            if isFree(x, y):
                score = evaluate_position(x, y)
                if score > best_score:
                    best_score = score
                    best_move = (x, y)
    return best_move

def evaluate_position(x, y):
    score = 0
    directions = [(1, 0), (0, 1), (1, 1), (1, -1)]  # Horizontal, Vertical, Diagonal droite, Diagonal gauche
    for dx, dy in directions:
        count = 0
        # Vérifier les pierres de l'IA dans une direction
        for i in range(1, 5):
            nx, ny = x + dx * i, y + dy * i
            if 0 <= nx < pp.size and 0 <= ny < pp.size and board[nx][ny] == 1:
                count += 1
            else:
                break
        score += count
    return score
###### OFFENSIVE MOVE ######



def brain_end():
    send_debug_message('\n---------------------------------------\n> **Fin de la transmission** *Bip biiiip 💻*\n``` ```')

def brain_about():
    pp.pipeOut(pp.infotext)

# "overwrites" functions in pisqpipe module
pp.brain_init = brain_init
pp.brain_restart = brain_restart
pp.brain_my = brain_my
pp.brain_opponents = brain_opponents
pp.brain_block = brain_block
pp.brain_takeback = brain_takeback
pp.brain_turn = brain_turn
pp.brain_end = brain_end
pp.brain_about = brain_about

def main():
    pp.main()

if __name__ == "__main__":
    main()
