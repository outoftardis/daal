@echo off
REM SPDX-FileCopyrightText: 2019-2020 Intel Corporation
REM
REM SPDX-License-Identifier: CC-BY-4.0
REM SPDX-License-Identifier: MIT

if /I %1 == html goto :html
if /I %1 == doxygen goto :doxygen
if /I %1 == parse-doxygen goto :parse-doxygen
if /I %1 == clean goto :clean

:html
sphinx-build -M html source build -q
goto :eof

:doxygen
pushd "doxygen/oneapi"
doxygen
popd
goto :eof

:parse-doxygen
if not exist build mkdir build
python -m dalapi.doxypy.cli doxygen/oneapi/doxygen/xml --compact > build/tree.yaml
goto :eof

:clean
rd /s /q build
goto :eof