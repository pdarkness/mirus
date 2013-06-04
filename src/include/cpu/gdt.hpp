#ifndef _MIRUS_KERNEL_CPU_GDT_H_
#define _MIRUS_KERNEL_CPU_GDT_H_

#include <mem/memory.hpp>

namespace mirus {
    // entry in the gdt
    class gdt_entry {
    public:
        unsigned short limit_low;
        unsigned short base_low;
        unsigned char base_middle;
        unsigned char access;
        unsigned char granularity;
        unsigned char base_high;
    } __attribute__ ((__packed__));

    // ptr to the gdt
    class gdt_ptr {
    public:
        unsigned short limit;
        unsigned int base;
    } __attribute__ ((__packed__));

    void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);

    // install the gdt
    void gdt_install();
}

#endif