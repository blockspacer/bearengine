#pragma once
namespace BearEngine
{
	typedef BearResource<BearGraphics::BearTexture2DRef> BearTexture2DRef;
	typedef BearResource<BearGraphics::BearPixelShaderRef> BearPixelShaderRef;
	typedef BearResource<BearGraphics::BearVertexShaderRef> BearVertexShaderRef;
	typedef BearResource<BearCore::BearMemoryMultiRef<BearFont>> BearFontRef;
	typedef BearResource<BearCore::BearMemoryMultiRef<BearAnimateArray2D>> BearAnimateArray2DRef;
	class BEARENGINE_API BearResourceManager :public BearObject
	{
		BEAR_OBJECT(BearResourceManager);
		BearResourceManager(const BearName&type);
		~BearResourceManager();
	public:
		void CompilePixelShader(const BearName&name);
		void CompileVertexShader(const BearName&name);

		virtual BearAnimateArray2DRef* GetAnimateArray2D(const BearName&name);
		virtual void Destroy(BearAnimateArray2DRef*&anim);

		virtual BearFontRef* GetFont(const BearName&name);
		virtual void Destroy(BearFontRef*&font);

		virtual BearTexture2DRef* GetTexture2D(const BearName&name);
		virtual void Destroy(BearTexture2DRef*&texture);

		virtual BearPixelShaderRef* GetPixelShader(const BearName&name);
		virtual void Destroy(BearPixelShaderRef*&shader);

		virtual BearVertexShaderRef* GetVertexShader(const BearName&name);
		virtual void Destroy(BearVertexShaderRef*&shader);

		virtual void Destroy();

	private:
		virtual void Update(float time) override;
		virtual void Save(BearCore::BearOutputStream*stream) override;
		virtual void Load(const BearCore::BearInputStream*stream) override;
	protected:
		BearCore::BearMap<BearName, BearGraphics::BearTexture2DRef> MapTextures;
		BearCore::BearMap<BearName, BearGraphics::BearPixelShaderRef> MapPixelShaders;
		BearCore::BearMap<BearName, BearGraphics::BearVertexShaderRef> MapVertexShaders;
		BearCore::BearMap<BearName, BearCore::BearMemoryMultiRef<BearFont>> MapFonts;
		BearCore::BearMap<BearName, BearCore::BearMemoryMultiRef<BearAnimateArray2D>> MapAnimation2DArray;

	};
	BEARENGINE_API extern BearResourceManager*GResourceManager;
}