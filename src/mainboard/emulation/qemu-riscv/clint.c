/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <mcall.h>
#include <device/mmio.h>
#include <mainboard/addressmap.h>

/* This function is used to initialize HLS()->time/HLS()->timecmp  */
void mtime_init(void)
{
	long hart_id = read_csr(mhartid);
	HLS()->time = (uint64_t *)(QEMU_VIRT_CLINT + 0xbff8);
	HLS()->timecmp = (uint64_t *)(QEMU_VIRT_CLINT + 0x4000 + 8 * hart_id);
}

void set_msip(int hartid, int val)
{
	write32((void *)(QEMU_VIRT_CLINT + 4 * (uintptr_t)hartid), !!val);
}
