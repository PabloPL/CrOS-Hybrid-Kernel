/*
 *  arch/arm/include/asm/hardware/gic.h
 *
 *  Copyright (C) 2002 ARM Limited, All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */
#ifndef __ASM_ARM_HARDWARE_GIC_H
#define __ASM_ARM_HARDWARE_GIC_H

#include <linux/compiler.h>

#define GIC_CPU_CTRL			0x00
#define GIC_CPU_PRIMASK			0x04
#define GIC_CPU_BINPOINT		0x08
#define GIC_CPU_INTACK			0x0c
#define GIC_CPU_EOI			0x10
#define GIC_CPU_RUNNINGPRI		0x14
#define GIC_CPU_HIGHPRI			0x18

#define GIC_DIST_CTRL			0x000
#define GIC_DIST_CTR			0x004
#define GIC_DIST_ENABLE_SET		0x100
#define GIC_DIST_ENABLE_CLEAR		0x180
#define GIC_DIST_PENDING_SET		0x200
#define GIC_DIST_PENDING_CLEAR		0x280
#define GIC_DIST_ACTIVE_BIT		0x300
#define GIC_DIST_PRI			0x400
#define GIC_DIST_TARGET			0x800
#define GIC_DIST_CONFIG			0xc00
#define GIC_DIST_SOFTINT		0xf00

#ifndef __ASSEMBLY__
struct irq_data;

extern void __iomem *gic_cpu_base_addr;

void gic_init(unsigned int, unsigned int, void __iomem *, void __iomem *);
void gic_secondary_init(unsigned int);
void gic_dist_save(unsigned int gic_nr);
void gic_dist_restore(unsigned int gic_nr);
void gic_cpu_exit(unsigned int gic_nr);
void gic_cascade_irq(unsigned int gic_nr, unsigned int irq);
void gic_raise_softirq(const struct cpumask *mask, unsigned int irq);
void gic_enable_ppi(unsigned int);

void gic_ack_irq(struct irq_data *d);
void gic_mask_irq(struct irq_data *d);
void gic_unmask_irq(struct irq_data *d);
int gic_set_type(struct irq_data *d, unsigned int type);
#ifdef CONFIG_SMP
int gic_set_cpu(struct irq_data *d, const struct cpumask *mask_val, bool force);
#endif
#endif

#endif
