CDS 101 lecture slides (Summer 2018) <img src="https://travis-ci.com/mason-cds-intro-comput-sci/summer-2018-lecture-slides.svg?branch=master" />
====================================

R Markdown source files for the CDS 101 slides used during the summer 2018 semester at George Mason University.
After installing the [necessary requirements](#requirements), see [How-To Guide](#how-to-guide) for simple instructions on how to automate the installation of the [R package dependencies](#dependencies) and knitting the R Markdown files.

*   [Requirements](#requirements)
*   [Dependencies](#dependencies)
*   [How-To Guide](#how-to-guide)
*   [License](#license)

Requirements
------------

At a minimum, to knit the R Markdown files in this repo you should have the following installed:

*   [R][r-lang-url] (>=3.4)

*   [RStudio][rstudio-url] (>=1.1.456), [preview release][rstudio-preview] recommended

*   [Rtools][rtools-ucb-mirror] (Windows only), full install, match the Rtools version to the R version you have installed

*   [git][git-download-page] (optional), allows you to clone this repository

Dependencies
------------

The following R packages and versions are needed to be able to knit all the R Markdown files into remark.js slides in this repository: 

|  package  |  version |
| :-------: | :------: |
| broom     | >= 0.5.0 |
| dplyr     | >= 0.7.6 |
| forcats   | >= 0.3.0 |
| ggplot2   | >= 3.0.0 |
| gridExtra | >= 2.3   |
| infer     | >= 0.3.1 |
| lubridate | >= 1.7.4 |
| modelr    | >= 0.1.2 |
| purrr     | >= 0.2.5 |
| readr     | >= 1.1.1 |
| robotstxt | >= 0.6.0 |
| rvest     | >= 0.3.2 |
| stringr   | >= 1.3.1 |
| tidyr     | >= 0.8.1 |
| tidyverse | >= 1.2.1 |
| xaringan  | >= 0.7   |

This list is also in the [DESCRIPTION](./DESCRIPTION) file.

How-To Guide
------------

> The following step-by-step instructions are for **after** you install the software listed in the [Requirements](#requirements) section.

1.  Launch RStudio and obtain a copy of this repo either by [cloning it as a new RStudio project][rstudio-git-explainer] or by downloading and unzipping an archive of it.
    If you unzipped this repo, then use the file browser in RStudio to navigate to the unzipped folder and click the file [`summer-2018-lecture-slides.Rproj`](./summer-2018-lecture-slides.Rproj) to activate the project.
    If you cloned this repo as a new project, then the project should be activated already.

2.  In the *Console* window, type the following to install the `remotes` package:
    
    ```r
    install.packages("remotes", repos = "https://cran.rstudio.com")
    ```
    
3.  Remain in the *Console* and type the following to have R automatically install all the necessary packages for you:

    ```r
    remotes::install_deps()
    ```
    
4.  In the window in the upper-right, there should be a tab that says **Build**, click it.
    This should reveal a mostly empty window with a thin bar at the top with a couple of buttons.
    One of those buttons says *Build All*.
    Click it to start the knitting process.
    
    *Tip: The keyboard shortcut for this is `CTRL ALT B`.*
    
5.  After some activity in the window, the knitting process will complete and the slideshows will be available as HTML files in a new folder named `build/`.
    
To view the slideshows, open the HTML files using your web browser.
I recommend using Google Chrome for this as it seems to provide the best rendering of these files.
Finally, these HTML files depend on the relative location of the other folders in this repository in order to work correctly.
This means you will not be able to move these files elsewhere on your file system and still expect the remark.js slideshow to work.

License
-------

[![Creative Commons License][cc-by-sa-4-img]][cc-by-sa-4]

Unless otherwise noted, the materials in this repository are licensed under a [Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa-4].

[r-lang-url]:            https://www.r-project.org/
[cc-by-sa-4]:            http://creativecommons.org/licenses/by-sa/4.0/
[rstudio-url]:           https://www.rstudio.com/products/rstudio/download/preview/
[cc-by-sa-4-img]:        https://i.creativecommons.org/l/by-sa/4.0/88x31.png
[git-download-page]:     https://git-scm.com/download
[rtools-ucb-mirror]:     https://cran.cnr.berkeley.edu/bin/windows/Rtools/
[rstudio-git-explainer]: http://happygitwithr.com/rstudio-git-github.html#clone-the-new-github-repository-to-your-computer-via-rstudio
