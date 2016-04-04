rm(list = ls())
setwd("~/Documents/ProjetCEvolutionRep")


titre = "Diagramme_pT25pA9Pres2"
titreG = paste(titre,".pdf",sep = "")
titreT = paste(titre,".txt",sep = "")
#pdf(titreG)
d <- read.table(titreT, header = F, col.names = c("T", "Ainit", "Etat"))

plot(d$T,d$Ainit, col = d$Etat +2, cex = 10, pch = 15, 
     main = "Diagramme de Phase des équilibres entre génotypes bactériens A et B ",
     xlab = "Durée avant changement de milieu",
     ylab = "Concentration initiale en glucose")
legend("topright", legend = c("Exclusion de B", "Cohabitation","Extinction"), col = c(3,2,1), pch = 15)
#dev.off()