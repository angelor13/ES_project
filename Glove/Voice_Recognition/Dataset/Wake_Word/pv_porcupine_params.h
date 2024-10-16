/*
    Copyright 2024 Picovoice Inc.

    You may not use this file except in compliance with the license. A copy of the license is located in the "LICENSE"
    file accompanying this source.

    Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on
    an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the
    specific language governing permissions and limitations under the License.
*/
#ifndef PV_PPN_PARAMS_H
#define PV_PPN_PARAMS_H

#include <stdint.h>

#ifdef __cplusplus

extern "C" {

#endif

// UUID = ca-e2-bc-6b-0c-09-dc-55
// Wake-word = Eagle Eye
// Version = 3.0.0
static const uint8_t KEYWORD_ARRAY[476] __attribute__ ((aligned (16))) = {
        0x86, 0x86, 0x43, 0x09, 0xdd, 0x1a, 0xae, 0x00, 0x39, 0x8e, 0xab, 0x76, 0x15, 0x96, 0x36, 0xac, 0xe1, 0x70,
        0xe0, 0xcf, 0x48, 0xd9, 0xe4, 0xf4, 0xa3, 0x53, 0xdc, 0xa5, 0xed, 0x5d, 0xaf, 0xe4, 0x47, 0x48, 0x94, 0x4c,
        0x1e, 0x10, 0x19, 0xa5, 0x56, 0x0f, 0x89, 0x12, 0x5b, 0x3b, 0x6b, 0x72, 0x78, 0x5c, 0x67, 0x80, 0x90, 0x80,
        0x03, 0x4d, 0x5f, 0x55, 0x9e, 0x22, 0x87, 0xe2, 0xaa, 0x0b, 0x81, 0x3c, 0xbe, 0xa2, 0x9b, 0x23, 0xa6, 0x83,
        0x49, 0x17, 0x7d, 0x4a, 0x63, 0x0a, 0x4c, 0x8e, 0x31, 0xea, 0x4b, 0x87, 0x0a, 0xcb, 0x06, 0xc6, 0x88, 0xb0,
        0x45, 0xf7, 0x33, 0x0f, 0x08, 0xf5, 0x38, 0x3b, 0x6b, 0x60, 0xc6, 0x47, 0x57, 0x55, 0xb2, 0xe3, 0x31, 0x13,
        0x06, 0x47, 0x22, 0x49, 0x9b, 0x1e, 0x65, 0x0f, 0xc3, 0xc7, 0x2f, 0x67, 0x18, 0x1a, 0x0f, 0x51, 0xf5, 0x4e,
        0xb4, 0xa4, 0xc8, 0x63, 0x1c, 0x96, 0xaa, 0xde, 0x52, 0x0f, 0xb9, 0x10, 0x2e, 0x35, 0x20, 0xae, 0x53, 0x45,
        0x67, 0x02, 0x5f, 0x7f, 0x2b, 0x36, 0x68, 0x00, 0x27, 0xfa, 0x1e, 0xba, 0xe8, 0xdd, 0xf6, 0x00, 0x4e, 0x08,
        0x0f, 0x55, 0xd7, 0xbd, 0xef, 0xd5, 0xbd, 0x65, 0x42, 0x78, 0x87, 0x26, 0xc2, 0xf8, 0x29, 0x2c, 0x60, 0x43,
        0xf9, 0x1e, 0xea, 0x04, 0xaf, 0x9b, 0xbe, 0xde, 0x5d, 0x5f, 0x2b, 0x5f, 0xcc, 0x8d, 0x39, 0xed, 0xf0, 0x72,
        0x39, 0x87, 0xed, 0xed, 0x8b, 0x2a, 0xe1, 0xc0, 0x8c, 0x2d, 0x4e, 0x37, 0x59, 0x11, 0x05, 0xc8, 0x6b, 0x07,
        0xbe, 0x2b, 0xf9, 0x21, 0xd0, 0x77, 0x10, 0x4c, 0x7f, 0x7c, 0xde, 0x73, 0x5a, 0x0f, 0x2e, 0xa2, 0xd3, 0xa5,
        0xd2, 0x6d, 0x0f, 0xef, 0xc4, 0x7e, 0x16, 0x3b, 0x05, 0x3a, 0xad, 0x45, 0x6d, 0x3c, 0xa5, 0x1b, 0x71, 0xff,
        0x12, 0x34, 0xd6, 0x78, 0xfc, 0xf5, 0x7f, 0xf4, 0x32, 0x8d, 0xcd, 0x19, 0x76, 0xf4, 0x03, 0xd3, 0x9b, 0x50,
        0x9b, 0xb6, 0x74, 0xf0, 0x47, 0x2c, 0x2b, 0x6b, 0xf5, 0x24, 0xee, 0x4b, 0xd0, 0xe8, 0xd3, 0x53, 0xb5, 0x17,
        0x36, 0xb1, 0x8a, 0x42, 0xcb, 0x99, 0x37, 0x6a, 0xd2, 0x58, 0x94, 0x4b, 0xf7, 0x28, 0x05, 0x88, 0x9d, 0x80,
        0xf4, 0xef, 0x54, 0x96, 0xe0, 0x6b, 0x2b, 0x29, 0x08, 0x58, 0xa4, 0x63, 0x16, 0xe7, 0xea, 0x25, 0xfd, 0x67,
        0xa9, 0xfa, 0xf5, 0x38, 0xd8, 0xcc, 0x93, 0x6d, 0xfc, 0xa4, 0x21, 0xf0, 0x22, 0x77, 0xcb, 0x8e, 0x52, 0x7b,
        0x7e, 0x7f, 0xdb, 0x21, 0x61, 0x04, 0x71, 0x1a, 0x56, 0x01, 0x7b, 0xcf, 0x1c, 0x7f, 0x95, 0x30, 0x8b, 0xcf,
        0xd1, 0x66, 0x5a, 0x2e, 0x3a, 0x56, 0xcc, 0x48, 0xad, 0xf0, 0x5f, 0xce, 0x98, 0x7e, 0xa6, 0x31, 0x40, 0xee,
        0xec, 0x23, 0x30, 0x86, 0xeb, 0xd9, 0x96, 0x0c, 0x0d, 0x2e, 0x1d, 0x9a, 0xe6, 0x01, 0x4d, 0x1d, 0x64, 0x34,
        0x06, 0xf1, 0x9b, 0x44, 0x3a, 0x31, 0x52, 0x02, 0xc8, 0xce, 0xea, 0xa4, 0x72, 0xbf, 0xcb, 0xa4, 0x70, 0x92,
        0x78, 0xe0, 0xf7, 0x12, 0x90, 0xa4, 0xe8, 0x9c, 0x2c, 0x0b, 0x42, 0x7e, 0xc3, 0xa4, 0x8d, 0xad, 0xe9, 0x33,
        0xc4, 0x5e, 0xc1, 0x72, 0x68, 0x04, 0x84, 0x80, 0x06, 0x9c, 0xd6, 0x2a, 0xb4, 0xea, 0x25, 0x66, 0xb8, 0x1d,
        0x4d, 0xce, 0x18, 0xb4, 0x85, 0x1b, 0x30, 0x71, 0x4c, 0x09, 0xe8, 0xf1, 0x49, 0x33, 0x35, 0x0e, 0xc9, 0x68,
        0x08, 0xfe, 0x5d, 0xac, 0x5b, 0x36, 0x62, 0x60
};

static const uint32_t KEYWORD_ARRAY_LENGTH = 476;

#ifdef __cplusplus

}

#endif // __cplusplus

#endif // PV_PPN_PARAMS_H