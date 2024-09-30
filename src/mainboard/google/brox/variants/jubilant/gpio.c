/* SPDX-License-Identifier: GPL-2.0-or-later */

#include <baseboard/gpio.h>
#include <baseboard/variants.h>
#include <commonlib/helpers.h>
#include <soc/gpio.h>
#include <vendorcode/google/chromeos/chromeos.h>

/* Pad configuration in ramstage */
static const struct pad_config override_gpio_table[] = {
	/* GPP_E11 : [NF2: THC0_SPI1_CLK NF6: USB_C_GPP_E11 NF7: GSPI0_CLK] ==> WWAN_CFG0 */
	PAD_CFG_GPI(GPP_E11, NONE, PLTRST),
	/* GPP_E17 : [NF2: THC0_SPI1_INT# NF6: USB_C_GPP_E17] ==> WWAN_CFG02 */
	PAD_CFG_GPI(GPP_E17, NONE, PLTRST),
	/* GPP_D7 : SRCCLKREQ2_L ==> WWAN_RF_DISABLE_ODL */
	PAD_CFG_GPO_LOCK(GPP_D7, 1, LOCK_CONFIG),
	/* GPP_D5 : SRCCLKREQ0_L ==> WWAN_SAR_ODL */
	PAD_CFG_GPO(GPP_D5, 1, DEEP),
	/* GPP_S4 : SNDW2_CLK/DMIC_CLK_B0 ==> WWAN_WLAN_COEX1 */
	PAD_CFG_GPI(GPP_S4, NONE, DEEP),
	/* GPP_S5 : SNDW2_DATA/DMIC_CLK_B1 ==> WWAN_WLAN_COEX2 */
	PAD_CFG_GPI(GPP_S5, NONE, DEEP),
	/* GPP_F6 : [NF1: CNV_PA_BLANKING NF6: USB_C_GPP_F6] ==>WWAN_WLAN_COEX3 */
	PAD_CFG_GPI(GPP_F6, NONE, DEEP),
	/*
	 * GPP_A12 : [NF1: SATAXPCIE1 NF2: SATAGP1 NF4: SRCCLKREQ9B# NF6: USB_C_GPP_A12]
	 *  ==> WWAN_PWR_EN
	 */
	PAD_CFG_GPO_LOCK(GPP_A12, 1, LOCK_CONFIG),
	/* GPP_H23 : SRCCLKREQ5_L ==> WWAN_RST_L */
	PAD_CFG_GPO_LOCK(GPP_H23, 1, LOCK_CONFIG),
	/* GPP_F21 : [NF1: Reserved NF6: USB_C_GPP_F21] ==> WWAN_FCPO_L */
	PAD_CFG_GPO_LOCK(GPP_F21, 1, LOCK_CONFIG),
	/* GPP_H19 : SRCCLKREQ4_L ==> SAR1_INT_L */
	PAD_CFG_GPI_APIC_LOCK(GPP_H19, NONE, LEVEL, NONE, LOCK_CONFIG),

	/* GPP_D2 : [NF1: ISH_GP2 NF2: BK2 NF5: SBK2 NF6: USB_C_GPP_D2] ==> EN_FP_PWR (active high) */
	PAD_CFG_GPO_LOCK(GPP_D2, 0, LOCK_CONFIG),
	/* GPP_D3 : [NF1: ISH_GP3 NF2: BK3 NF5: SBK3 NF6: USB_C_GPP_D3] ==> IPCH_FP_BOOT0 (active high) */
	PAD_CFG_GPO_LOCK(GPP_D3, 0, LOCK_CONFIG),
	/* GPP_D15 : ISH_UART0_RTS_L/I2C7B_SDA ==> FPMCU_RST_J_SUB_L (active low) */
	PAD_CFG_GPO_LOCK(GPP_D15, 0, LOCK_CONFIG),
	/* GPP_D13 : [NF1: ISH_UART0_RXD NF3: I2C6_SDA NF6: USB_C_GPP_D13] ==> FP GSPI INT */
	PAD_CFG_GPI_IRQ_WAKE(GPP_D13, NONE, PWROK, LEVEL, INVERT),
	/* GPP_F11 : [NF3: THC1_SPI2_CLK NF4: GSPI1_CLK NF6: USB_C_GPP_F11] ==>  FP GSPI CLK */
	PAD_CFG_NF_LOCK(GPP_F11, NONE, NF4, LOCK_CONFIG),
	/* GPP_F12 : [NF1: GSXDOUT NF3: THC1_SPI2_IO0 NF4: GSPI1_MOSI NF5: I2C1A_SCL
	NF6: USB_C_GPP_F12] ==> FP GSPI DO */
	PAD_CFG_NF_LOCK(GPP_F12, NONE, NF4, LOCK_CONFIG),
	/* GPP_F13 : [NF1: GSXSLOAD NF3: THC1_SPI2_IO1 NF4: GSPI1_MISIO NF5: I2C1A_SDA
	NF6: USB_C_GPP_F13] ==> SFP GSPI DI */
	PAD_CFG_NF_LOCK(GPP_F13, NONE, NF4, LOCK_CONFIG),
	/* GPP_F16 : [NF1: GSXCLK NF3: THC1_SPI2_CS# NF4: GSPI1_CS0# NF6: USB_C_GPP_F16] ==> FP GSPI CS */
	PAD_CFG_NF_LOCK(GPP_F16, NONE, NF4, LOCK_CONFIG),

	/* GPP_F14 : [NF1: GSXDIN NF3: THC1_SPI2_IO2 NF6: USB_C_GPP_F14] ==> PCH_TCHSCR_REPORT_EN */
	PAD_CFG_GPO(GPP_F14, 0, DEEP),

	/* GPP_E7 : [NF1: PROC_GP1 NF6: USB_C_GPP_E7] ==> EN_UCAM_PWR */
	PAD_CFG_GPO(GPP_E7, 1, PLTRST),

	/* GPP_B5 : [NF1: ISH_I2C0_SDA NF2: I2C2_SDA NF6: USB_C_GPP_B5] ==> PCH_I2C_MISC_R_SDA (SAR, HP) */
	PAD_CFG_NF(GPP_B5, NONE, DEEP, NF2),
	/* GPP_B6 : [NF1: ISH_I2C0_SCL NF2: I2C2_SCL NF6: USB_C_GPP_B6] ==> PCH_I2C_MISC_R_SCL (SAR, HP) */
	PAD_CFG_NF(GPP_B6, NONE, DEEP, NF2),

	/* GPP_S6 : SNDW3_CLK/DMIC_CLK_A1 ==> HP_INT_L (Headphone interrupt) */
	PAD_CFG_GPI_INT(GPP_S6, NONE, PLTRST, EDGE_BOTH),
	/* GPP_D19 : [NF1: I2S_MCLK1_OUT NF6: USB_C_GPP_D19] ==> I2S_MCLK_R (headphone MCLK) */
	PAD_CFG_NF(GPP_D19, NONE, DEEP, NF1),
	/* GPP_R0 : [NF1: HDA_BCLK NF2: I2S0_SCLK NF3: DMIC_CLK_B0 NF4: HDAPROC_BCLK] ==> I2S0_SCLK */
	PAD_CFG_NF(GPP_R0, NONE, PLTRST, NF2),
	/* GPP_R1 : [NF1: HDA_SYNC NF3: DMIC_CLK_B1] ==> I2S0_SFRM */
	PAD_CFG_NF(GPP_R1, NONE, PLTRST, NF2),
	/* GPP_R2 : [NF1: HDA_SDO NF2: I2S0_TXD NF4: HDAPROC_SDO] ==> I2S0_TXD */
	PAD_CFG_NF(GPP_R2, NONE, PLTRST, NF2),
	/* GPP_R3 : [NF1: HDA_SDI0 NF2: I2S0_RXD NF4: HDAPROC_SDI] ==> I2S0_RXD */
	PAD_CFG_NF(GPP_R3, NONE, PLTRST, NF2),

	/* GPP_F20 : [NF1: Reserved NF6: USB_C_GPP_F20] ==> SPK enable (active high) */
	PAD_CFG_GPO(GPP_F20, 1, DEEP),
	/* GPP_S0 : SNDW0_CLL/I2S1_SCLK ==> SPK I2S_CLK */
	PAD_CFG_NF(GPP_S0, NONE, PLTRST, NF4),
	/* GPP_S1 : SNDW0_DATA/I2S1_SFRM ==> SPK I2S_FRAME */
	PAD_CFG_NF(GPP_S1, NONE, PLTRST, NF4),
	/* GPP_S2 : [NF1: SNDW1_CLK NF2: DMIC_CKL_A0 NF4: I2S1_TXD] ==> SPK I2S_TX */
	PAD_CFG_NF(GPP_S2, NONE, PLTRST, NF4),
	/* GPP_S3 : [NF1: SNDW1_DATA NF2: DMIC_DAGPP_D1TA0 NF4: I2S1_RXD] ==> SPK I2S_RX */
	PAD_CFG_NF(GPP_S3, NONE, PLTRST, NF4),

	/* GPP_R4 : HDA_RST_L/I2S2_SCLK/DMIC_CLK_A0 ==> DMIC_CLK_A0 */
	PAD_CFG_NF(GPP_R4, NONE, PLTRST, NF3),
	/* GPP_R5 : HDA_SDI1/I2S2_SFRM/DMIC_DATA0 ==> SDMIC_DATA0 */
	PAD_CFG_NF(GPP_R5, NONE, PLTRST, NF3),
	/* GPP_R6 : I2S2_TXD/DMIC_CLK_A1 ==> DMIC_CLK_A1 */
	PAD_CFG_NF(GPP_R6, NONE, PLTRST, NF3),
	/* GPP_R7 : I2S2_RXD/DMIC_DATA1 ==> DMIC_DATA1 */
	PAD_CFG_NF(GPP_R7, NONE, PLTRST, NF3),

	/* GPP_E15 : SRCCLK_OE8_L ==> MEM_STRAP_0 */
	PAD_CFG_GPI(GPP_E15, NONE, PLTRST),
	/* GPP_E12 : THC0_SPI1_IO1/I2C0A_SDA/GSPI0_MISO ==> MEM_STRAP_1 */
	PAD_CFG_GPI(GPP_E12, NONE, PLTRST),
	/* GPP_E13 : THC0_SPI1_IO0/I2C0A_SCL/GSPI0_MOSI ==> MEM_STRAP_2 */
	PAD_CFG_GPI(GPP_E13, NONE, PLTRST),
	/* GPP_E10 : THC0_SPI1_CS_L/GSPI0_CS0_L ==> MEM_STRAP_3 */
	PAD_CFG_GPI(GPP_E10,  NONE, PLTRST),
	/* GPP_S7 : SNDW3_DATA/DMIC_DATA1 ==> MEM_CH_SEL */
	PAD_CFG_GPI(GPP_S7, NONE, DEEP),
};

/* Early pad configuration in bootblock */
static const struct pad_config early_gpio_table[] = {

	/*
	 * GPP_A12 : [NF1: SATAXPCIE1 NF2: SATAGP1 NF4: SRCCLKREQ9B# NF6: USB_C_GPP_A12]
	 *  ==> WWAN_PWR_EN
	 */
	PAD_CFG_GPO_LOCK(GPP_A12, 1, LOCK_CONFIG),
	/* GPP_H23 : SRCCLKREQ5_L ==> WWAN_RST_L */
	PAD_CFG_GPO_LOCK(GPP_H23, 0, LOCK_CONFIG),
	/* GPP_F21 : [NF1: Reserved NF6: USB_C_GPP_F21] ==> WWAN_FCPO_L */
	PAD_CFG_GPO_LOCK(GPP_F21, 0, LOCK_CONFIG),

	/*
	 * FP_RST_ODL comes out of reset as hi-z and does not have an external pull-down.
	 * To ensure proper power sequencing for the FPMCU device, reset signal is driven low
	 * early on in bootblock, followed by enabling of power. Reset signal is deasserted
	 * later on in ramstage. Since reset signal is asserted in bootblock, it results in
	 * FPMCU not working after a S3 resume. This is a known issue.
	 */
	/* GPP_D15 : ISH_UART0_RTS_L/I2C7B_SDA ==> FPMCU_RST_J_SUB_L (active low) */
	PAD_CFG_GPO(GPP_D15, 0, DEEP),
	/* D2  : ISH_GP2 ==> EN_FP_PWR */
	PAD_CFG_GPO(GPP_D2, 1, DEEP),

	/* GPP_F9 : [NF1: BOOTMPC NF6: USB_C_GPP_F9] ==> SSD_PERST_L */
	PAD_CFG_GPO(GPP_F9, 0, DEEP),
	/* GPP_D11 : [] ==> EN_PP3300_SSD (NC) */
	PAD_NC(GPP_D11, NONE),

	/* GPP_E2  : THC0_SPI1_IO3 ==> GSC_PCH_INT_ODL */
	PAD_CFG_GPI_APIC_LOCK(GPP_E2, NONE, LEVEL, INVERT, LOCK_CONFIG),
	/* GPP_E8 : GPP_E8 ==> PCH_WP_OD */
	PAD_CFG_GPI_LOCK(GPP_E8, NONE, LOCK_CONFIG),
	/* GPP_H8 : [NF1: I2C4_SDA NF2: CNV_MFUART2_RXD NF6: USB_C_GPP_H8] ==> PCH_I2C_GSC_SDA */
	PAD_CFG_NF(GPP_H8, NONE, DEEP, NF1),
	/* GPP_H9 : [NF1: I2C4_SCL NF2: CNV_MFUART2_TXD] ==> PCH_I2C_GSC_SCL */
	PAD_CFG_NF(GPP_H9, NONE, DEEP, NF1),

	/* H10 : UART0_RXD ==> UART_PCH_RX_DBG_TX */
	PAD_CFG_NF(GPP_H10, NONE, PLTRST, NF2),
	/* H11 : UART0_TXD ==> UART_PCH_TX_DBG_RX */
	PAD_CFG_NF(GPP_H11, NONE, PLTRST, NF2),

	/* GPP_S7 : SNDW3_DATA/DMIC_DATA1 ==> MEM_CH_SEL */
	PAD_CFG_GPI(GPP_S7, NONE, DEEP),

	/* CPU PCIe VGPIO for PEG60 */
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_48, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_49, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_50, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_51, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_52, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_53, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_54, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_55, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_56, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_57, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_58, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_59, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_60, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_61, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_62, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_63, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_76, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_77, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_78, NONE, PLTRST, NF1),
	PAD_CFG_NF_VWEN(GPP_vGPIO_PCIE_79, NONE, PLTRST, NF1),
};

static const struct pad_config romstage_gpio_table[] = {
	/* GPP_D15 : ISH_UART0_RTS_L/I2C7B_SDA ==> FPMCU_RST_J_SUB_L (active low) */
	PAD_CFG_GPO(GPP_D15, 0, DEEP),
	/* D2  : ISH_GP2 ==> EN_FP_PWR */
	PAD_CFG_GPO(GPP_D2, 0, DEEP),

	/*
	 * GPP_A12 : [NF1: SATAXPCIE1 NF2: SATAGP1 NF4: SRCCLKREQ9B# NF6: USB_C_GPP_A12]
	 *  ==> WWAN_PWR_EN
	 */
	PAD_CFG_GPO_LOCK(GPP_A12, 1, LOCK_CONFIG),
	/* GPP_H23 : SRCCLKREQ5_L ==> WWAN_RST_L */
	PAD_CFG_GPO_LOCK(GPP_H23, 0, LOCK_CONFIG),
	/* GPP_F21 : [NF1: Reserved NF6: USB_C_GPP_F21] ==> WWAN_FCPO_L */
	PAD_CFG_GPO_LOCK(GPP_F21, 1, LOCK_CONFIG),

	/* GPP_E15 : SRCCLK_OE8_L ==> MEM_STRAP_0 */
	PAD_CFG_GPI(GPP_E15, NONE, PLTRST),
	/* GPP_E12 : THC0_SPI1_IO1/I2C0A_SDA/GSPI0_MISO ==> MEM_STRAP_1 */
	PAD_CFG_GPI(GPP_E12, NONE, PLTRST),
	/* GPP_E13 : THC0_SPI1_IO0/I2C0A_SCL/GSPI0_MOSI ==> MEM_STRAP_2 */
	PAD_CFG_GPI(GPP_E13, NONE, PLTRST),
	/* GPP_E10 : THC0_SPI1_CS_L/GSPI0_CS0_L ==> MEM_STRAP_3 */
	PAD_CFG_GPI(GPP_E10,  NONE, PLTRST),
	/* GPP_S7 : SNDW3_DATA/DMIC_DATA1 ==> MEM_CH_SEL */
	PAD_CFG_GPI(GPP_S7, NONE, DEEP),

	/* GPP_F7 : [NF6: USB_C_GPP_F7] ==> EN_PP3300_TCHSCR */
	PAD_CFG_GPO(GPP_F7, 1, PLTRST),
	/* GPP_F17 : [NF3: THC1_SPI2_RST# NF6: USB_C_GPP_F17] ==> TCHSCR_RST_L */
	PAD_CFG_GPO(GPP_F17, 0, DEEP),

	/* GPP_F9 : [NF1: BOOTMPC NF6: USB_C_GPP_F9] ==> SSD_PERST_L */
	PAD_CFG_GPO(GPP_F9, 1, DEEP),
};

const struct pad_config *variant_gpio_override_table(size_t *num)
{
	*num = ARRAY_SIZE(override_gpio_table);
	return override_gpio_table;
}

const struct pad_config *variant_early_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(early_gpio_table);
	return early_gpio_table;
}

const struct pad_config *variant_romstage_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(romstage_gpio_table);
	return romstage_gpio_table;
}

static const struct cros_gpio cros_gpios[] = {
	CROS_GPIO_REC_AL(CROS_GPIO_VIRTUAL, CROS_GPIO_DEVICE_NAME),
	CROS_GPIO_WP_AH(GPIO_PCH_WP, CROS_GPIO_DEVICE_NAME),
};

DECLARE_WEAK_CROS_GPIOS(cros_gpios);
