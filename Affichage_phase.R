rm(list = ls())
setwd("~/Documents/ProjetCEvolutionRep")

titre = "Diagramme_pT25pA9Pres2"
titreG = paste(titre,".pdf",sep = "")
titreT = paste(titre,".txt",sep = "")
#pdf(titreG)
d <- read.table(titreT, header = F, col.names = c("T", "Ainit", "Etat"))
etat <- factor(d$"Etat")
mescouleurs <- rainbow(length(levels(etat)))
plot(d$"T", d$"Ainit", pch = 19, col = mescouleurs[etat],
     main = "Diagramme de phase de la culture bactérienne en l'absence de mutation. D = 0.1",
     xlab = "Durée avant changement de milieu",
     ylab = "Concentration initiale en glucose")
legend("topleft", inset = 0.02, pch = 19, legend = levels(etat), col = mescouleurs)
#dev.off()

