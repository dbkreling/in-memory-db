#!/bin/bash

autoscan # scan the system for dependencies
mv configure.scan configure.ac
autoreconf # uses configure.ac as the input to generate config

