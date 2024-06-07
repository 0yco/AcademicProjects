# functions and variables for pipe AI and functions that communicate with manager through pipes
# don't modify this file

import sys

DEBUG      = False
ABOUT_FUNC = True
DEBUG_EVAL = True

# information about a game - you should use these variables
"""time for one turn in milliseconds"""
info_timeout_turn = 30000
"""total time for a game"""
info_timeout_match = 1000000000
"""left time for a game"""
info_time_left = 1000000000
"""maximum memory in bytes, zero if unlimited"""
info_max_memory = 0
"""0: human opponent, 1: AI opponent, 2: tournament, 3: network tournament"""
info_game_type = 1
"""0: five or more stones win, 1: exactly five stones win"""
info_exact5 = 0
"""0: gomoku, 1: renju"""
info_renju = 0
"""0: single game, 1: continuous"""
info_continuous = 0
"""return from brain_turn when terminateAI > 0"""
terminateAI = None
"""tick count at the beginning of turn"""
start_time = None
"""folder for persistent files"""
dataFolder = ""

event1, event2 = None, None


###### BRAIN TO OVERWRITE ######
def brain_init():
    """create the board and call pipeOut("OK") or pipeOut("ERROR Maximal board size is ..")"""
    raise NotImplementedError
def brain_restart():
    """delete old board, create new board, call pipeOut("OK")"""
    raise NotImplementedError
def brain_turn():
    """choose your move and call do_mymove(x,y), 0 <= x < size, 0 <= y < size"""
    raise NotImplementedError
def brain_my(x, y):
    """put your move to the board"""
    raise NotImplementedError
def brain_opponents(x, y):
    """put opponent's move to the board"""
    raise NotImplementedError
def brain_block(x, y):
    """square [x,y] belongs to a winning line (when info_continuous is 1)"""
    raise NotImplementedError
def brain_takeback(x, y):
    """clear one square, return value: 0: success, 1: not supported, 2: error"""
    raise NotImplementedError
def brain_end():
    """delete temporary files, free resources"""
    raise NotImplementedError
def brain_eval(x, y):
    """display evaluation of square [x,y]"""
    raise NotImplementedError
"""AI identification (copyright, version)"""
infotext = ""
def brain_about():
    """call pipeOut(" your AI info ")"""
    raise NotImplementedError


###### UTILS ######
def pipeOut(what):
	"""write a line to sys.stdout"""
	ret = len(what)
	print(what)
	sys.stdout.flush()

def do_mymove(x, y):
	brain_my(x, y)
	pipeOut("{},{}".format(x,y))

def suggest(x, y):
	"""send suggest"""
	pipeOut("SUGGEST {},{}".format(x,y))

def safeInt(v):
	"""helper function for parsing strings to int"""
	try:
		ret = int(v)
		return ret
	except:
		return None

def parse_coord(param):
	"""parse coordinates x,y"""
	if param.count(",") != 1:
		return None
	x, comma, y = param.partition(',')
	x, y = [safeInt(v) for v in (x, y)]
	if any(v is None for v in (x,y)):
		return None, None
	if x < 0 or y < 0 or x >= size or y >= size:
		return None, None
	return x, y

def parse_3int_chk(param):
	"""parse coordinates x,y and player number z"""
	if param.count(',') != 2:
		return None, None, None
	x, y, z = param.split(',')
	x, y, z = [safeInt(v) for v in (x,y,z)]
	if any(v is None for v in (x,y,z)):
		return None, None, None
	return x, y, z


###### MAIN ######
def main():
    while True:
        try:
            command_line = input()
            command, *args = command_line.split()

            ####### MANDATORY COMMANDS #######
            if command == "START":
                global size
                size = safeInt(args[0])
                if size < 5:
                    size = 0
                    pipeOut("ERROR bad START parameter")
                else:
                    size = int(size)
                    brain_init()

            elif command == "TURN":
                x, y = parse_coord(args[0])
                if x is None or y is None:
                    pipeOut("ERROR bad coordinates")
                else:
                    if brain_opponents(x, y) == True:
                        brain_turn()

            elif command == "BEGIN":
                brain_turn()

            elif command == "BOARD":
                last_who = -1
                while True:
                    try:
                        input_line = input()
                        if input_line == "DONE":
                            if last_who == 2:
                                brain_turn()
                            elif last_who == 3:
                                brain_end()
                            break
                        x, y, who = parse_3int_chk(input_line)
                        last_who = who
                        if x is None:
                            pipeOut("ERROR bad coordinates")
                            continue
                        if who == 1:
                            brain_my(x, y)
                        elif who == 2:
                            brain_opponents(x, y)
                        elif who == 3:
                            brain_block(x, y)
                        else:
                            pipeOut("ERROR bad who")
                    except EOFError:
                        return

            elif command == "INFO":
                if args[0] == "timeout_turn":
                    info_timeout_turn = safeInt(args[1])
                elif args[0] == "timeout_match":
                    info_timeout_match = safeInt(args[1])
                elif args[0] == "time_left":
                    info_time_left = safeInt(args[1])
                elif args[0] == "max_memory":
                    info_max_memory = safeInt(args[1])
                elif args[0] == "game_type":
                    info_game_type = safeInt(args[1])
                elif args[0] == "rule":
                    info_exact5 = safeInt(args[1])
                elif args[0] == "folder":
                    dataFolder = args[1]
                elif args[0] == "evaluate":
                    brain_eval(safeInt(args[1]), safeInt(args[2]))
                else:
                    pipeOut("ERROR unknown command")

            elif command == "ABOUT":
                brain_about()

            elif command == "END":
                brain_end()
                exit(0)

            else:
                print(f"Unknown command: {command}")

        except EOFError:
            break  # Exit on EOF (end of file)

if __name__ == "__main__":
    main()
