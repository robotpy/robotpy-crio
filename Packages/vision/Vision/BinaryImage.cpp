/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2008. All Rights Reserved.							  */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in $(WIND_BASE)/WPILib.  */
/*----------------------------------------------------------------------------*/

#include "BinaryImage.h"
#include "Utility.h"

/** Private NI function needed to write to the VxWorks target */
IMAQ_FUNC int Priv_SetWriteFileAllowed(UINT32 enable); 

BinaryImage::BinaryImage() : MonoImage()
{
}

BinaryImage::~BinaryImage()
{
}

/**
 * Get then number of particles for the image.
 * @returns the number of particles found for the image.
 */
int BinaryImage::GetNumberParticles()
{
	int numParticles = 0;
	int success = imaqCountParticles(m_imaqImage, 1, &numParticles);
	wpi_imaqAssert(success, "IMAQ Error counting particles");
	return numParticles;
}

/**
 * Get a single particle analysis report.
 * Get one (of possibly many) particle analysis reports for an image.
 * @param particleNumber Which particle analysis report to return.
 * @returns the selected particle analysis report
 */
ParticleAnalysisReport BinaryImage::GetParticleAnalysisReport(int particleNumber)
{
	ParticleAnalysisReport par;
	int success = 0;

	success = imaqGetImageSize(m_imaqImage, &par.imageWidth, &par.imageHeight);
	wpi_imaqAssert(success, "Error getting image size");

	par.particleIndex = particleNumber;		

	success = imaqCountParticles(m_imaqImage, TRUE, NULL);
	wpi_imaqAssert(success, "Error counting particles");

	par.center_mass_x = (int) ParticleMeasurement(particleNumber, IMAQ_MT_CENTER_OF_MASS_X);
	par.center_mass_y = (int) ParticleMeasurement(particleNumber, IMAQ_MT_CENTER_OF_MASS_Y);
	par.particleArea = (int) ParticleMeasurement(particleNumber, IMAQ_MT_AREA);	
	par.boundingRect.top = (int) ParticleMeasurement(particleNumber, IMAQ_MT_BOUNDING_RECT_TOP);
	par.boundingRect.left = (int) ParticleMeasurement(particleNumber, IMAQ_MT_BOUNDING_RECT_LEFT);
	par.boundingRect.height = (int) ParticleMeasurement(particleNumber, IMAQ_MT_BOUNDING_RECT_HEIGHT);
	par.boundingRect.width = (int) ParticleMeasurement(particleNumber, IMAQ_MT_BOUNDING_RECT_WIDTH);
	par.particleToImagePercent = ParticleMeasurement(particleNumber, IMAQ_MT_AREA_BY_IMAGE_AREA);
	par.particleQuality = ParticleMeasurement(particleNumber, IMAQ_MT_AREA_BY_PARTICLE_AND_HOLES_AREA);

	/* normalized position (-1 to 1) */
	par.center_mass_x_normalized = NormalizeFromRange(par.center_mass_x, par.imageWidth);
	par.center_mass_y_normalized = NormalizeFromRange(par.center_mass_y, par.imageHeight);

	return par;
}


/**
 * Get an ordered vector of particles for the image.
 * Create a vector of particle analysis reports sorted by size for an image.
 * The vector contains the actual report structures.
 * @returns a pointer to the vector of particle analysis reports. The caller must delete the
 * vector when finished using it.
 */
vector<ParticleAnalysisReport>* BinaryImage::GetOrderedParticleAnalysisReports()
{
	vector<ParticleAnalysisReport>* particles = new vector<ParticleAnalysisReport>;
	int particleCount = GetNumberParticles();
	for(int particleIndex = 0; particleIndex < particleCount; particleIndex++)
	{
		particles->push_back(GetParticleAnalysisReport(particleIndex));
	}
	sort(particles->begin(), particles->end(), CompareParticleSizes);
	return particles;
}

/**
 * Write a binary image to flash.
 * Writes the binary image to flash on the cRIO for later inspection.
 * @param fileName the name of the image file written to the flash.
 */
void BinaryImage::Write(const char *fileName)
{
	RGBValue colorTable[256];
	Priv_SetWriteFileAllowed(1);
	memset(colorTable, 0, sizeof(colorTable));
	colorTable[0].R = 0;
	colorTable[1].R = 255;
	colorTable[0].G = colorTable[1].G = 0;
	colorTable[0].B = colorTable[1].B = 0;
	colorTable[0].alpha = colorTable[1].alpha = 0;
	imaqWriteFile(m_imaqImage, fileName, colorTable);
	return;
}

/**
 * Measure a single parameter for an image.
 * Get the measurement for a single parameter about an image by calling the imaqMeasureParticle
 * function for the selected parameter.
 * @param image the image to measure
 * @param particleNumber which particle in the set of particles
 * @param whatToMeasure the imaq MeasurementType (what to measure)
 * @returns the value of the measurement
 */
double BinaryImage::ParticleMeasurement(int particleNumber, MeasurementType whatToMeasure)
{
	double returnDouble;
	int success;
	success = imaqMeasureParticle(m_imaqImage, particleNumber, 0, whatToMeasure, &returnDouble);
	wpi_imaqAssert(success, "Error measuring particle");
	if (!success) return 0.0;
	else return returnDouble;
}

//Normalizes to [-1,1]
double BinaryImage::NormalizeFromRange(double position, int range)
{
	return(((position*2.0)/(double)range)-1.0);
}

/**
 * The compare helper function for sort.
 * This function compares two particle analysis reports as a helper for the sort function.
 * @param particle1 The first particle to compare
 * @param particle2 the second particle to compare
 * @returns true if particle1 is greater than particle2
 */
bool BinaryImage::CompareParticleSizes(ParticleAnalysisReport particle1, ParticleAnalysisReport particle2)
{
	return particle1.particleToImagePercent > particle2.particleToImagePercent; //we want descending sort order
}


