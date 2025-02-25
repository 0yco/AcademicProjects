# Panoramix

## Context 📜

The year is **50 BC**. Gaul is almost entirely occupied by the Romans, except for **one small village of indomitable Gauls** who still resist. These villagers rely on a **magic potion** prepared by their druid, which gives them superhuman strength to fight the Romans.

The druid brews a **pot of potion**, and the villagers take servings before heading into battle. When the pot is empty, a villager wakes up the druid to refill it. However, the druid has a limited number of refills before running out of ingredients.

## Project Overview ⚙️

This project focuses on **thread and mutex programming** to handle synchronization between the druid and villagers efficiently. The goal is to implement a simulation where villagers consume potion, fight, and request refills when necessary.

## Usage 🚀

```sh
./panoramix <nb_villagers> <pot_size> <nb_fights> <nb_refills>
```

### Parameters:

- **nb\_villagers**: Number of villagers (must be > 0).
- **pot\_size**: Maximum potion servings in the pot (must be > 0).
- **nb\_fights**: Maximum number of fights each villager engages in (must be > 0).
- **nb\_refills**: Maximum number of times the druid can refill the pot (must be > 0).

### Example Execution:

```sh
./panoramix 3 5 3 1
```

#### Output Example:

```
Druid: I’m ready... but sleepy...
Villager 2: Going into battle!
Villager 1: Going into battle!
Villager 0: Going into battle!
Villager 2: I need a drink... I see 5 servings left.
Villager 0: I need a drink... I see 4 servings left.
...
Druid: I’m out of viscum. I’m going back to... zZz
Villager 0: I’m going to sleep now.
Villager 1: I’m going to sleep now.
Villager 2: I’m going to sleep now.
```

## Architecture 🏗️

The project is divided into **multiple threads**:

- **Villagers**: Run on separate threads, consume potion, and fight until their fight limit is reached.
- **Druid**: Runs on a separate thread, wakes up to refill the potion pot when requested, and sleeps when out of ingredients.
- **Synchronization**: Managed using **mutexes** to avoid race conditions between villagers accessing the potion pot.

## Notes 📌

- If the **pot is empty**, villagers must wait for the druid to refill it before continuing their battles.
- If the **druid runs out of ingredients**, villagers must finish their battles with whatever potion is left.
- When a villager reaches their maximum number of fights, they **go to sleep**.

## My Conclusion 🏁

This project was fun and a good point for beginning the exercise in **multi-threading, synchronization, and resource management**. And who do not love Asterix & Obelix ?
