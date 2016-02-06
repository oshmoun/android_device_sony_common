/*
 * Copyright (C) 2016 The CyanogenMod Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

// Constants: file paths
#define EXEC_TOYBOX "/sbin/toybox"
#define SBIN_CPIO_ANDROID "/sbin/ramdisk.cpio"

// Prototype: elf ramdisk extraction
int extract_ramdisk(int argc, const char** argv);

// Main: executable
int main(int __attribute__((unused)) argc, char** __attribute__((unused)) argv)
{
    // Unpack ramdisk
    const char* argv_ramdiskcpio[] = { EXEC_TOYBOX, "cpio", "-i", "-F",
            SBIN_CPIO_ANDROID, nullptr };
    execv(argv_ramdiskcpio[0], const_cast<char* const*>(&argv_ramdiskcpio[0]));

    // Launch ramdisk /init
    const char* argv_init[] = { "/init", nullptr };
    execv(argv_init[0], const_cast<char* const*>(&argv_init[0]));

    return 0;
}
