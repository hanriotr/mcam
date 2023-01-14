#pragma once

#include "pnl/pnl_random.h"
#include "pnl/pnl_vector.h"
#include "pnl/pnl_matrix.h"

/// \brief Modèle de Black Scholes
class BlackScholesModel
{
public:
    int size_; /// nombre d'actifs du modèle
    double r_; /// taux d'intérêt
    double rho_; /// paramètre de corrélation
    PnlVect *sigma_; /// vecteur de volatilités
    PnlVect *divid_; /// vecteur des dividendes
    PnlVect *spot_; /// valeurs initiales des sous-jacents
    BlackScholesModel(int size, double r, double rho, PnlVect* sigma, PnlVect* divid, PnlVect* spot);
    PnlMat *L_; // Matrice racine carré de la corrélation

    /**
     * Génère une trajectoire du modèle et la stocke dans path
     *
     * @param[out] path contient une trajectoire du modèle.
     * C'est une matrice de taille (nbTimeSteps+1) x d
     * @param[in] T  maturité
     * @param[in] nbTimeSteps nombre de dates de constatation
     */
    void asset(PnlMat *path, double T, int dates, PnlRng *rng);

    /**
     * Génère une trajectoire du modèle et la stocke dans vect
     *
     * @param[out] path contient une trajectoire du modèle.
     * C'est un vecteur de taille nbTimeSteps+1
     * @param[in] T  maturité
     * @param[in] nbTimeSteps nombre de dates de constatation
     */
    void assetVect(PnlVect *vect, int j, double T, int dates, PnlRng *rng);
};
