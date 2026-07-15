[![Sponsor @ssilverman button](https://img.shields.io/badge/Sponsor-30363d.svg?logo=githubsponsors&logoColor=EA4AAA)](https://github.com/sponsors/ssilverman "Sponsor @ssilverman on GitHub")
or
[![Buy Me a Coffee donate button](https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00)](https://www.buymeacoffee.com/ssilverman "Donate to this project using Buy Me a Coffee")

# _TeensyRegs_, a new and more modern way to access and modify registers

_Version: 0.1.0-snapshot_

This library supplies a new and more modern way to access and modify registers.
It uses modern C++ features to avoid defines, macros, and other
avoidable mistakes.

## Table of contents

1. [Introduction](#introduction)
2. [Cookbook](#cookbook)
   1. [Whole registers](#whole-registers)
   2. [Partial registers](#partial-registers)
3. [To do](#to-do)

## Introduction

Accessing and modifying registers can be error-prone and "noisy". For example,
modifying only parts of a register often requires a clear-and-set approach with
helper macros or functions so as to avoid leaving 1-bits accidentally set.
Constants are repetitively used, cutting and pasting code to define register
parts that only have small differences in the name is easy to get wrong, and
the code is often hard to read.

Wouldn't it be nice to set parts of a register like this:

```c++
IOMUXC_GPR_GPR1_ENET1_CLK_SEL     = 0;
IOMUXC_GPR_GPR1_ENET_IPG_CLK_S_EN = 1;
IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR  = 1;

// ...do stuff...

IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR = 0;
```

...instead of this?

```c++
clearAndSet32(
    &IOMUXC_GPR_GPR1,
    IOMUXC_GPR_GPR1_ENET1_CLK_SEL,
    IOMUXC_GPR_GPR1_ENET_IPG_CLK_S_EN | IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR);

// ...do stuff...

clearAndSet32(&IOMUXC_GPR_GPR1, IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR, 0);
```

This project makes registers, parts of registers, and register values first
class objects that compile down to similar code that

## Cookbook

### Whole registers

### Partial registers

## To do

1. Make it prettier, if possible
2. Remove friction discovered from use
3. More constants or enums instead of numbers

---

Copyright (c) 2026 Shawn Silverman
