#library loading
library(dendextend)
library(ape)
library(phylogram)
library(dplyr)
#tree loading to separate variables
normal <- read.tree("prank_topo.treefile") %>% as.phylo() %>%as.dendrogram.phylo()
anomal <- read.tree("dialign_topo.treefile") %>% as.dendrogram.phylo()
#Make a list of two trees you want to compare
dend_list <- dendlist(normal,anomal)
#Run tanglegram algoritm on those trees
dend_list %>%
  #First step to untangle stem - make them as similar as possible
  untangle(method = "step2") %>%
  #Then we are drawing lines between identical leafs
  tanglegram(
    lwd = 1.5,
    edge.lwd = 1, center = TRUE,
    margin_inner=8,
    rank_branches = T,
    #The names of the trees on the graph
    main_left = "PRANK",
    main_right = "Dialign",
  )