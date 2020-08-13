
# Team-gilbert

This is HackBio repository for team-gilbert as a part of stage 1 of the internship

<h1 align="center">Hello 👋, We are Team-Gilbert 👋</h1>
<h3 align="center">The team of 10 scientists for HackBio-2020 Virtual Bioinformatics Internship </h3>



# Project

![HackBio](https://github.com/Team-Gilbert/team-gilbert/blob/hildred/stage1/hackbio.jpeg) <br>
Image Source: [@tbi_internship](https://twitter.com/tbi_internship)

> The goal of this project is to find biological data that can be analyzed with Linux based bioinformatics softwares,
> analyze the data and provide visual representations of the results in a google drive folder.


<h1 align="center">Project: </h1>
<h1 align="center"> Comparative Genomics of Mycoplasma hominis </h1>



# Pipeline

![Workflow](https://github.com/Team-Gilbert/team-gilbert/blob/hildred/stage1/image.png)									



# What we want to answer
> Genetic relationship among Mycoplasma hominis strains

 

# Dependencies
- Conda (Anaconda/miniconda)
- Clustal Omega
- ClustalW
- Mafft
- Muscle
- PRANK
- T-Coffee



# Installation

# Install Anaconda
* wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh  && sh Miniconda3-latest-Linux-x86_64.sh 

# Create Conda environments
* conda create -n gilbert-phylo muscle mafft t-coffee dialign-tx prank iqtree clustalo clustalw
* conda create -n gilbert-prep blast prokka

# Download Mycoplasma Genome
* cat Mycoplasma_genomes.csv | awk -F ',' '{print $15}' | tail -n +2 | sed 's/ftp:/rsync:/g' > links.txt
* while read p; do rsync --copy-links --recursive --times --verbose $p ./; done < links.txt




# Usage

# Run MSA using Clustal Omega
> clustalo --in=input.fasta

# Run MSA using ClustalW
> clustalw [-infile] file.ext

# Run MSA using Mafft
> mafft in > out

# Run MSA using Muscle
> muscle -in input.fasta -out output.fasta

# Run MSA using PRANK
> prank -d=input_file -t=tree_file -o=output_file

# Run MSA using T-coffee
> t_coffee in-file.fasta




# For participants

# GOALS FOR STAGE 1
- Form a group of 5 - 10 participants
- Identify a project
- Download dependency softwares
- Get genomic data
- Analyse data using softwares
- Create phylogenetic trees
- Compare trees

# TEAM MEMBERS
- @Ayodeji
- @grape
- @Haniel
- @Highzhikk
- @Hildred
- @KHATEN
- @Oluwatomisin
- @pavlo
- @Rajesh
- @Semilogo

