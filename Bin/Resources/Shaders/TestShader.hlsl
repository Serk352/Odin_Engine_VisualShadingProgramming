//1
struct VS_INPUT
{
    float3 Position : POSITION0;
    float4 Color : COLOR0;
    float3 Normal : NORMAL0;
    float2 UV : TEXCOORD0;
    float3 BiNormal : BINORMAL0;
    float3 Tangent : TANGENT0;

};
//12
struct VS_OUTPUT
{
    float4 Position : SV_POSITION;
    float4 Color : COLOR0;
    float2 UV : TEXCOORD0;
    float3 Normal : NORMAL0;    
    float3 BiNormal : BINORMAL0;
    float3 Tangent : TANGENT0;
};
//22
struct PS_OUTPUT 
{
    float4 Color : SV_Target0;
};

//28
cbuffer MAtrixVIew : register(b0)
{
    float4x4 ViewMatrix;
};  
//33
cbuffer MatrixProjection : register(b1)
{
    float4x4 ProjMatrix;
};

cbuffer MatrixWorld : register(b2)
{
    float4x4 WorldMatrix;
}

cbuffer MatrixScale: register(b3)
{
    float4x4 ScaleMatrix;
}
cbuffer MatrixRotateX: register(b4)
{
    float4x4 RotateXMatrix;
}
cbuffer MatrixRotateY : register(b5)
{
    float4x4 RotateYMatrix;
}
cbuffer MatrixRotateZ : register(b6)
{
    float4x4 RotateZMatrix;
}
cbuffer MatrixTranslate: register(b7)
{
    float4x4 TranslateMatrix;
}



cbuffer LigthPos : register(b8)
{
    float4 LightP;
}

//float4 Lightp : register(b8);
SamplerState mySamplerColor : register(s0);
SamplerState mySamplerNormal : register(s1);

Texture2D myTextureColor : register(t0);
Texture2D myTextureNormal : register(t1);


VS_OUTPUT VS_MAIN(VS_INPUT Input)
{

    VS_OUTPUT Output = (VS_OUTPUT)0;

    float4x4 Rotate = mul(RotateXMatrix, RotateYMatrix);
    Rotate = mul(Rotate, RotateZMatrix);

  //  Rotate = RotateYMatrix;

    float4x4 World = mul(WorldMatrix, ScaleMatrix);
    World = mul(World, Rotate);
    World = mul(World, TranslateMatrix);


   float4x4 WorldView =  mul(World, ViewMatrix);
    float4x4 Final = mul(WorldView, ProjMatrix);

  //  final = mul(ViewMatrix, ProjMatrix);


    Output.Position = mul(float4(Input.Position.xyz, 1), Final);
   // Output.Position = mul(float4(Input.Position.xyz, 1), ProjMatrix);
    

    //Output.Position = float4(Input.Position, 1.0f);
   
    
   /* Output.Color = Input.Color;*/
    Output.UV = Input.UV;
    Output.Normal = Input.Normal;
    Output.BiNormal = Input.BiNormal;
    Output.Tangent = Input.Tangent;


    return Output;

}

PS_OUTPUT PS_MAIN(VS_OUTPUT Input)
{
    PS_OUTPUT Output = (PS_OUTPUT)0;

    float3 Light = normalize(LightP.xyz);
    float3 Normal = normalize(Input.Normal);

    float3x3 TBN;
    TBN[0] = normalize(Input.Tangent);
    TBN[1] = normalize(Input.BiNormal);
    TBN[2] = normalize(Input.Normal);

    float3 NormalFT = (myTextureNormal.Sample(mySamplerNormal, Input.UV)).xyz;

//    float incidence = saturate(dot(Light, Normal));
    
    NormalFT = 2.0f * NormalFT - 1.0f;
    NormalFT = normalize(NormalFT);

    NormalFT = normalize(mul(TBN, NormalFT));
    
    float incidence = saturate(dot(normalize(Light), Normal));

    float4 Color = (myTextureColor.Sample(mySamplerColor, Input.UV));
    

    // Output.Color = Color * incidence;

    
    float a = dot(LightP.xyz, Input.Normal);

    Output.Color = Color*incidence; // float4(1.0f, 0.0f, 0.0f, 0.0f)*a; //NBeta; //float4(1.0f,0.0f,0.0f,0.0f) * a;

    return Output;
}


