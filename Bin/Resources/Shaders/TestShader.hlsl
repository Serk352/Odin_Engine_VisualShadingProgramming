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



cbuffer LigthPos : register(b2)
{
    float4 LightP;
}


SamplerState mySamplerColor : register(s0);
SamplerState mySamplerNormal : register(s1);

Texture2D myTextureColor : register(t0);
Texture2D myTextureNormal : register(t1);


VS_OUTPUT VS_MAIN(VS_INPUT Input)
{

    VS_OUTPUT Output = (VS_OUTPUT)0;

    
    float4x4 Final = mul(ViewMatrix, ProjMatrix);

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


//     Output.Color = myTextureColor.Sample(mySamplerColor, Input.UV);
    
    //Output.Color = myTextureNormal.Sample(mySamplerNormal, Input.UV);
    float3 Light = normalize(LightP.xyz);
   // Light.x=-30.0f;
   // Light.y=2.0f;
   // Light.z=1.0f;

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
    
    //Color = float4(1.0f, 0.0f, 0.0f, 1.0f);

    Output.Color = Color * incidence;


    return Output;
}

