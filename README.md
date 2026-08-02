# Instant Complete Reset

A small quality of life mod for Geometry Dash that lets you restart a level the instant you're done with it. no waiting for the end screen animation to finish, no navigating menus.

Press **R** at any point after finishing a level, even while the completion animation is still playing, and the level restarts immediately.

<p align="center">
  <img src="logo.png" width="150" alt="Instant Complete Reset logo" />
</p>

## Why

Every time you complete a level in Geometry Dash, there's a short animation before you're dropped back into the menu or given the option to retry. If you're grinding attempts on a level or practicing or aura farming, that animation adds up fast. This mod skips it entirely. hit R and you're straight back into the level.

## How it works

Geode's normal keyboard event pipeline doesn't fire while the completion animation is playing, so this mod polls the key state directly during that window and triggers a reset the moment R is detected — rather than waiting for the animation to hand control back first.

## Installation

1. Install [Geode](https://geode-sdk.org/) if you haven't already.
2. Grab the `.geode` file from the [Releases](../../releases) page (or build it yourself see below).
3. Drop it into your Geode mods folder, or install it directly through the in game mod browser.

## Building from source

```sh
# Requires the Geode CLI: https://github.com/geode-sdk/cli
geode build
```

Windows builds are also produced automatically via GitHub Actions on every push — see `.github/workflows/build.yml`.

## Compatibility

Currently built and tested for Windows on Geometry Dash 2.2081. Support for other platforms hasn't been tested yet.
