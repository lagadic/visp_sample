# visp_sample

ViSP sample code used as code snippet in ViSP doxygen [documentation](https://visp-doc.inria.fr/doxygen/visp-daily/index.html).


This project uses [ViSP](https://github.com/lagadic/visp) as 3rd-party.

See ViSP installation from source [tutorials](https://visp-doc.inria.fr/doxygen/visp-daily/tutorial_install_src.html).

Once ViSP is build, you can build `visp_sample` project:

```
$ cd $ViSP_WS
$ git clone https://github.com/lagadic/visp_sample
$ mkdir visp_sample-build
$ cd visp_sample-build
$ cmake ../visp_sample -DVISP_DIR=$ViSP_WS/visp-build
```
