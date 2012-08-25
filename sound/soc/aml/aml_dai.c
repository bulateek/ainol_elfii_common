#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/clk.h>

#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/initval.h>
#include <sound/soc.h>

#include <mach/hardware.h>

#include "aml_dai.h"

//#define AML_DAI_DEBUG

//#if defined(CONFIG_ARCH_MESON3) || defined(CONFIG_ARCH_MESON6)
//#define AML_DAI_PCM_SUPPORT
//#endif

static int aml_dai_i2s_startup(struct snd_pcm_substream *substream,
					struct snd_soc_dai *dai)
{	  	
#ifdef AML_DAI_DEBUG
	printk("***Entered %s:%s\n", __FILE__,__func__);
#endif
	return 0;
}

static void aml_dai_i2s_shutdown(struct snd_pcm_substream *substream,
					struct snd_soc_dai *dai)
{
#ifdef AML_DAI_DEBUG
	printk("***Entered %s:%s\n", __FILE__,__func__);
#endif
}

static int aml_dai_i2s_prepare(struct snd_pcm_substream *substream,
					struct snd_soc_dai *dai)
{
#ifdef AML_DAI_DEBUG
	printk("***Entered %s:%s\n", __FILE__,__func__);
#endif
	return 0;
}

static int aml_dai_i2s_hw_params(struct snd_pcm_substream *substream,
					struct snd_pcm_hw_params *params,
					struct snd_soc_dai *dai)
{
#ifdef AML_DAI_DEBUG
	printk("***Entered %s:%s\n", __FILE__,__func__);
#endif
	return 0;
}

static int aml_dai_set_i2s_fmt(struct snd_soc_dai *dai,
					unsigned int fmt)
{
#ifdef AML_DAI_DEBUG
	printk("***Entered %s:%s\n", __FILE__,__func__);
#endif
	return 0;
}

static int aml_dai_set_i2s_sysclk(struct snd_soc_dai *dai,
					int clk_id, unsigned int freq, int dir)
{
#ifdef AML_DAI_DEBUG
	printk("***Entered %s:%s\n", __FILE__,__func__);
#endif
	return 0;
}

#ifdef CONFIG_PM
static int aml_dai_i2s_suspend(struct snd_soc_dai *dai)
{
		
  printk("***Entered %s:%s\n", __FILE__,__func__);
  return 0;
}

static int aml_dai_i2s_resume(struct snd_soc_dai *dai)
{
  printk("***Entered %s:%s\n", __FILE__,__func__);
  return 0;
}

#else /* CONFIG_PM */
#  define aml_dai_i2s_suspend	NULL
#  define aml_dai_i2s_resume	NULL
#endif /* CONFIG_PM */

#ifdef AML_DAI_PCM_SUPPORT

static int aml_dai_pcm_startup(struct snd_pcm_substream *substream,
					struct snd_soc_dai *dai)
{	  	
#ifdef AML_DAI_DEBUG
	printk("***Entered %s:%s\n", __FILE__,__func__);
#endif
	return 0;
}

static void aml_dai_pcm_shutdown(struct snd_pcm_substream *substream,
					struct snd_soc_dai *dai)
{
#ifdef AML_DAI_DEBUG
	printk("***Entered %s:%s\n", __FILE__,__func__);
#endif
}

static int aml_dai_pcm_prepare(struct snd_pcm_substream *substream,
					struct snd_soc_dai *dai)
{
#ifdef AML_DAI_DEBUG
	printk("***Entered %s:%s\n", __FILE__,__func__);
#endif
	return 0;
}

static int aml_dai_pcm_hw_params(struct snd_pcm_substream *substream,
					struct snd_pcm_hw_params *params,
					struct snd_soc_dai *dai)
{
#ifdef AML_DAI_DEBUG
	printk("***Entered %s:%s\n", __FILE__,__func__);
#endif
	return 0;
}

static int aml_dai_set_pcm_fmt(struct snd_soc_dai *dai,
					unsigned int fmt)
{
#ifdef AML_DAI_DEBUG
	printk("***Entered %s:%s\n", __FILE__,__func__);
#endif
	return 0;
}

static int aml_dai_set_pcm_sysclk(struct snd_soc_dai *dai,
					int clk_id, unsigned int freq, int dir);
{
#ifdef AML_DAI_DEBUG
	printk("***Entered %s:%s\n", __FILE__,__func__);
#endif
	return 0;
}

#ifdef CONFIG_PM
static int aml_dai_pcm_suspend(struct snd_soc_dai *dai)
{
		
  printk("***Entered %s:%s\n", __FILE__,__func__);
  return 0;
}

static int aml_dai_pcm_resume(struct snd_soc_dai *dai)
{
  printk("***Entered %s:%s\n", __FILE__,__func__);
  return 0;
}

#else /* CONFIG_PM */
#  define aml_dai_i2s_suspend	NULL
#  define aml_dai_i2s_resume	NULL
#endif /* CONFIG_PM */

#endif

#define AML_DAI_I2S_RATES		(SNDRV_PCM_RATE_8000_96000)
#define AML_DAI_I2S_FORMATS		(SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S24_LE | SNDRV_PCM_FMTBIT_S32_LE)

#ifdef AML_DAI_PCM_SUPPORT
#define AML_DAI_PCM_RATES		(SNDRV_PCM_RATE_8000)
#define AML_DAI_PCM_FORMATS		(SNDRV_PCM_FMTBIT_S16_LE | SNDRV_PCM_FMTBIT_S24_LE | SNDRV_PCM_FMTBIT_S32_LE)
#endif

static struct snd_soc_dai_ops aml_dai_i2s_ops = {
	.startup	= aml_dai_i2s_startup,
	.shutdown	= aml_dai_i2s_shutdown,
	.prepare	= aml_dai_i2s_prepare,
	.hw_params	= aml_dai_i2s_hw_params,
	.set_fmt	= aml_dai_set_i2s_fmt,
	.set_sysclk	= aml_dai_set_i2s_sysclk,
};

#ifdef AML_DAI_PCM_SUPPORT
static struct snd_soc_dai_ops aml_dai_pcm_ops = {
	.startup	= aml_dai_pcm_startup,
	.shutdown	= aml_dai_pcm_shutdown,
	.prepare	= aml_dai_pcm_prepare,
	.hw_params	= aml_dai_pcm_hw_params,
	.set_fmt	= aml_dai_set_pcm_fmt,
	.set_sysclk	= aml_dai_set_pcm_sysclk,
};
#endif

struct snd_soc_dai_driver aml_dai[] = {
	{	.name = "aml-dai0",
		.id = 0,
		.suspend = aml_dai_i2s_suspend,
		.resume = aml_dai_i2s_resume,
		.playback = {
			.channels_min = 1,
			.channels_max = 2,
			.rates = AML_DAI_I2S_RATES,
			.formats = AML_DAI_I2S_FORMATS,},
		.capture = {
			.channels_min = 1,
			.channels_max = 2,
			.rates = AML_DAI_I2S_RATES,
			.formats = AML_DAI_I2S_FORMATS,},
		.ops = &aml_dai_i2s_ops,
	},
#ifdef AML_DAI_PCM_SUPPORT
	{	.name = "aml-dai1",
		.id = 1,
		.suspend = aml_dai_pcm_suspend,
		.resume = aml_dai_pcm_resume,
		.playback = {
			.channels_min = 1,
			.channels_max = 1,
			.rates = AML_DAI_PCM_RATES,
			.formats = AML_DAI_PCM_FORMATS,},
		.capture = {
			.channels_min = 1,
			.channels_max = 1,
			.rates = AML_DAI_PCM_RATES,
			.formats = AML_DAI_PCM_FORMATS,},
		.ops = &aml_dai_pcm_ops,
	},
#endif
};

EXPORT_SYMBOL_GPL(aml_dai);

static __devinit int aml_dai_probe(struct platform_device *pdev)
{
	printk(KERN_DEBUG "enter %s\n", __func__);
#if 0
	BUG_ON(pdev->id < 0);
	BUG_ON(pdev->id >= ARRAY_SIZE(aml_dai));
	return snd_soc_register_dai(&pdev->dev, &aml_dai[pdev->id]);
#else
	return snd_soc_register_dais(&pdev->dev, aml_dai, ARRAY_SIZE(aml_dai));
#endif
}

static int __devexit aml_dai_remove(struct platform_device *pdev)
{
	snd_soc_unregister_dai(&pdev->dev);
	return 0;
}

static struct platform_driver aml_dai_driver = {
	.driver = {
		.name = "aml-dai",
		.owner = THIS_MODULE,
	},

	.probe = aml_dai_probe,
	.remove = __devexit_p(aml_dai_remove),
};

static int __init aml_dai_modinit(void)
{
	return platform_driver_register(&aml_dai_driver);
}
module_init(aml_dai_modinit);

static void __exit aml_dai_modexit(void)
{
	platform_driver_unregister(&aml_dai_driver);
}
module_exit(aml_dai_modexit);

/* Module information */
MODULE_AUTHOR("AMLogic, Inc.");
MODULE_DESCRIPTION("AML DAI driver for ALSA");
MODULE_LICENSE("GPL");
