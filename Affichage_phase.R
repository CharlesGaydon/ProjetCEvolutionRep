rm(list = ls())
setwd("~/Documents/ProjetCEvolutionRep")


pdf("Phase.pdf")
d <- read.table("PhaseNpT50pA26Pres2", header = F, col.names = c("T", "Ainit", "Etat"))
etat <- factor(d$"Etat")
mescouleurs <- rainbow(length(levels(etat)))
plot(d$"T", d$"Ainit", pch = 19, col = mescouleurs[etat])
legend("topleft", inset = 0.02, pch = 19, legend = levels(etat), col = mescouleurs)
dev.off()

