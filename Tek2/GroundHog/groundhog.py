#!/usr/bin/env python3
import math
import sys


############# HELP #############
def help_h():
    try:
        if len(sys.argv) == 2 and sys.argv[1] == "-h":
            print("""SYNOPSIS
    ./groundhog period
DESCRIPTION
    period        the number of days defining a period""")
            sys.exit(0)
        else:
            return
    except ValueError:
        sys.exit(84)


############# ERROR HANDLING #############
def error_handling():
    if len(sys.argv) != 2:
        sys.exit(84)
    try:
        if int(sys.argv[1]) < 1:
            sys.exit(84)
    except:
        sys.exit(84)


############# CALCULATION #############
def compute_average(GH):
    if GH.get_day() < GH._period:
        return
    i = len(GH._values) - GH._period
    GH._average = 0
    for i in range(i, len(GH._values)):
        tmp = GH._values[i] - GH._values[i - 1]
        if tmp > 0:
            GH._average += tmp
    GH._average /= GH._period

def compute_standard_deviation(GH):
    if GH.get_day() < GH._period:
        return
    one = 0
    two = 0
    if len(GH._values) < GH._period:
        return
    for a in range(len(GH._values) - GH._period, len(GH._values)):
        one += GH._values[a]
        two += GH._values[a] * GH._values[a]
    GH._standard_deviation = math.sqrt(two / GH._period - (one / GH._period)**2)

def compute_relative_temp_evolution(GH):
    if GH.get_day() < GH._period:
        return
    if GH._values[-1 - GH._period] == 0:
        if GH._values[-1] > 0:
            GH._relative_temp_evolution = 100
        elif GH._values[-1] < 0:
            GH._relative_temp_evolution = -100
        else:
            GH._relative_temp_evolution = 0
    else:
        GH._relative_temp_evolution = ((GH._values[-1] / GH._values[-1-GH._period]) * 100) - 100
        GH._relative_temp_evolution = int(GH._relative_temp_evolution + (0.5 - int(GH._relative_temp_evolution < 0)))

def detect_switch(GH, older):
    if older == None or GH._relative_temp_evolution == None or GH.get_day() < GH._period:
        return
    if GH._relative_temp_evolution < 0 and older >= 0:
        GH._alerts += 1
        GH._isSwitched = True
    if GH._relative_temp_evolution >= 0 and older < 0:
        GH._alerts += 1
        GH._isSwitched = True

def update_weirdest_values():
    pass

def calculation(GH):
    while True:
        try:
            input = sys.stdin.readline()
            if input == "STOP\n":
                break
            temperature = float(input)
        except:
            sys.exit(84)
        if temperature < -273.15:
            sys.exit(84)
        older = GH._relative_temp_evolution
        GH.add_value(temperature)
        compute_average(GH)
        compute_standard_deviation(GH)
        compute_relative_temp_evolution(GH)
        detect_switch(GH, older)
        GH.display_prediction()
        if GH.get_day() >= GH._period:
            update_weirdest_values()
        GH._day += 1
    GH._weird_values = update_weirdest_values()
    GH.display_result()


############# MAIN #############
class GroundHog():
    # INIT
    def __init__(self, period):
        self._period = period
        self._values = []
        self._average = None
        self._standard_deviation = None
        self._relative_temp_evolution = None
        self._day = 0
        self._alerts = 0
        self._isSwitched = False
        self._weird_values = []


    def add_value(self, value):
        self._values.append(value)


    # GETTERS
    def get_period(self):
        return self._period
    def get_values(self):
        return self._values
    def get_average(self):
        return self._average
    def get_standard_deviation(self):
        return self._standard_deviation
    def get_relative_temp_evolution(self):
        return self._relative_temp_evolution
    def get_day(self):
        return self._day


    # DISPLAY
    def display_prediction(self):
        if self._average == None: print("g=nan", end="")
        else: print("g={:.2f}".format(self._average), end="")

        if self._relative_temp_evolution == None: print("\tr=nan", end="")
        else: print("\tr={:d}".format(self._relative_temp_evolution), end="")

        if self._standard_deviation == None: print("%\ts=nan", end="")
        else: print("%\ts={:.2f}".format(self._standard_deviation), end="")

        if self._isSwitched:
            print("\t\ta switch occurs")
            self._isSwitched = False
        else:
            print()

    def display_result(self):
        print("Global tendency switched {} times".format(self._alerts))
        print("5 weirdest values are:")
        # for i in range(5):
        #     print("{:.2f}".format(self._weird_values[i]))

def main():
    help_h()
    error_handling()
    calculation(GroundHog(int(sys.argv[1])))

if __name__ == "__main__":
    main()