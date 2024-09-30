/** @file

Copyright (c) 2024, Intel Corporation. All rights reserved.<BR>

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.
* Neither the name of Intel Corporation nor the names of its contributors may
  be used to endorse or promote products derived from this software without
  specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
  THE POSSIBILITY OF SUCH DAMAGE.

  This file is automatically generated. Please do NOT modify !!!

**/

#ifndef __FSP_ACPI_HOBS__
#define __FSP_ACPI_HOBS__

//Typecast HOB pointer to APEI table structure of ACPI version 6.2
#define FSP_RAS_ACPI_HOB_GUID             { 0x826785ee, 0xa8e0, 0x4d8f, { 0x82, 0x6f, 0x54, 0x29, 0x2c, 0xe7, 0x6f, 0xe6 } }

//Typecast HOB pointer to ACPI CXL CEDT table structure
#define FSP_CXL_CEDT_ACPI_HOB_GUID        { 0x5CB7A12A, 0x8B2D, 0x485A, { 0xB7, 0x04, 0xC0, 0x52, 0x49, 0x56, 0x81, 0xE7 } }

// Typecast HOB pointer to MEM_TRAINING_DATA_HOB_HEADER. 
// User with NDA clearance should refer to RC code for latest structure definition.
#define FSP_MEM_TRAINING_DATA_HOB_GUID    { 0x7e8b89e2, 0x8b84, 0x4cb3, { 0x86, 0x8f, 0x10, 0xb6, 0x78, 0x71, 0xa2, 0xc0 }}

// Typecast HOB pointer to EWL_PRIVATE_DATA. 
// User with NDA clearance should refer to RC code for latest structure definition.
#define FSP_EWL_ID_HOB_GUID                   { 0xd8e05800, 0x5e, 0x4462, { 0xaa, 0x3d, 0x9c, 0x6b, 0x47, 0x4, 0x92, 0xb } };

//Typecast HOB pointer to RAS_ACPI_PARAM_HOB_DATA;
#define RAS_ACPI_PARAM_HOB_GUID           {0x594dfe5c, 0x7a87, 0x49dc, { 0x8f, 0x33, 0xea, 0x83, 0x4d, 0x6f, 0x18, 0x90 } }

#endif  // __FSP_ACPI_HOBS__
