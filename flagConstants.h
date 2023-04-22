#ifndef FLAGCONSTANTS_H
#define FLAGCONSTANTS_H
#include <QVector>
#include <QString>

const QVector<QString> BASIC_COLOR_FLAGS = {"bw.png", "fr.png", "bg.png", "be.png", "al.png", "bv.png", "dk.png", "tt.png", "ws.png", "wf.png"};
const QVector<QString> COMPLEX_COLOR_FLAGS = {"er.png", "ec.png", "km.png", "za.png", "sc.png", "dm.png", "mz.png", "zm.png", "ke.png", "pe.png" };

const QVector<QString> SIMPLE_FLAGS = {"cl.png", "vn.png", "gm.png", "mc.png", "af.png", "at.png", "gb-eng.png", "cz.png", "mv.png", "so.png"};
const QVector<QString> MEANINGFUL_FLAGS = {"cy.png", "md.png", "lk.png", "pk.png", "es.png", "af.png", "ua.png", "vu.png", "mx.png", "my.png"};

const QVector<QString> NO_LETTER_OR_SEAL_FLAGS = {"am.png", "cn.png", "bf.bng", "ax.png", "nr.png", "mr.png", "sl.png", "vn.png", "to.png", "gh.png"};
const QVector<QString> LETTERED_FLAGS = {"sx.png", "sm.png", "gt.png", "gu.png", "vg.png", "bz.png"};

const QVector<QString> CHRISTIANITY_FLAGS = {"nz.png", "dm.png", "me.png", "no.png", "es.png" };
const QVector<QString> ISLAM_FLAGS = {"af.png", "az.png", "pk.png", "my.png", "tr.png" };
const QVector<QString> UNION_JACK_FLAGS = {"au.png", "nz.png", "tv.png", "fj.png" };

const QVector<QString> CORNER_FLAG_TEMPLATES = {"circleMiddleBottom.png", "circleMiddleTop.png", "flowerMiddleRight.png", "pentagonBottomLeft.png", "pentagonBottomRight.png", "treeMiddleLeft.png", "treeMiddleRight.png", "triangleTopLeft.png", "triangleTopRight.png"};
const QVector<QString> CENTER_FLAG_TEMPLATES = {"circleMiddle.png", "flowerMiddle.png", "polygonMiddle.png", "tigerMiddle.png", "triangleMiddle.png", "weirdShapeMiddle.png"};

#endif // FLAGCONSTANTS_H
